#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#include <boost/bind.hpp>

#include "common/module.hpp"
#include "gram/client.hpp"
#include "gram/protocol.hpp"
#include "common/thread.hpp"
#include "rsl.hpp"

namespace  {

class job_submit_listener
{
	std::size_t pending_jobs_;
	globus::thread::mutex mutex_;
	globus::thread::cond cond_;
public:
	job_submit_listener()
		: pending_jobs_(0)
		, mutex_()
		, cond_() {}

	~job_submit_listener()
	{
		globus::thread::mutex::scoped_lock lock(mutex_);
		while (pending_jobs_ > 0) cond_.wait(mutex_);
	}

	void job_submitting()
	{
		globus::thread::mutex::scoped_lock lock(mutex_);
		++pending_jobs_;
	}

	void job_submitted(globus::gram::error_code operation_ec, char const *job_contact)
	{
		std::cerr << __FUNCTION__ << "(error_code = " << globus::gram::error(operation_ec)
				  << ", job contact = " << std::string((job_contact == 0) ? "NULL" : job_contact) << ")" << std::endl;

		globus::thread::mutex::scoped_lock lock(mutex_);
		--pending_jobs_;
	}
};

class do_async_submit_job
	: public std::unary_function<std::string,globus::gram::error_code>
{
	globus::gram::client &client_;
	job_submit_listener &listener_;
public:
	do_async_submit_job(globus::gram::client &client, job_submit_listener &listener)
		: client_(client)
		, listener_(listener) {}
	globus::gram::error_code operator()(std::string const &rsl) const
	{
		using namespace globus::gram::protocol;
		globus::gram::error_code const result(
			globus::gram::async_submit_job(
				client_,
				rsl,
				boost::bind(&job_submit_listener::job_submitted, &listener_, _1, _2)));
		if (result != globus::gram::no_error) return result;
		listener_.job_submitting();
		return result;
	}
};

} // anonymous namespace

int main(const int argc, char const *argv[])
{
	if (argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " RESOURCE-MANAGER-CONTACT RSL-SPEC..." << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		globus::module gram_client_module(*GLOBUS_GRAM_CLIENT_MODULE);
		globus::module gram_rsl_module(*GLOBUS_RSL_MODULE);
		globus::gram::resource_manager_contact contact(argv[1]);
		globus::gram::client client(contact);

		std::vector<std::string> rsl_args(argv + 2, argv + argc);
		std::vector<globus::gram::error_code> results(rsl_args.size());

		job_submit_listener listener;
		transform(
			rsl_args.begin(), rsl_args.end(), results.begin(),
			do_async_submit_job(client, listener));

		std::vector<globus::gram::error_code>::const_iterator error_found =
			find_if(
				results.begin(),
				results.end(),
				std::not1(std::bind1st(std::equal_to<globus::gram::error_code>(), globus::gram::no_error)));
		if (error_found != results.end())
		{
			std::cerr << globus::gram::error(*error_found) << std::endl;
			return EXIT_FAILURE;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
