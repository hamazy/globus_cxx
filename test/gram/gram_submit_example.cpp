#include <iostream>

#include <boost/bind.hpp>

#include "common/module.hpp"
#include "gram/client.hpp"
#include "gram/protocol.hpp"

namespace  {

class state_change_listener
{
public:
	state_change_listener() {}
	void state_changed(globus::gram::protocol::job_state state, globus::gram::error_code ec) const
	{
		std::cerr << __FUNCTION__ << std::endl;
		switch (state)
		{
			using namespace globus::gram::protocol;
		case JOB_STATE_FAILED:
			std::cout << "JOB_STATE_FAILED" << std::endl;
			break;
		case JOB_STATE_DONE:
			std::cout << "JOB_STATE_DONE" << std::endl;
			break;
		default:
			break;
		}
	}
};

} // anonymous namespace

int main(const int argc, char const *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " RESOURCE-MANAGER-CONTACT RSL" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		globus::module gram_client_module(*GLOBUS_GRAM_CLIENT_MODULE);
		globus::gram::resource_manager_contact contact(argv[1]);
		globus::gram::client client(contact);

		using namespace globus::gram::protocol;
		state_change_listener const listener;
		globus::gram::error const error(
			globus::gram::request_job(
				client,
				argv[2],			// rsl
				JOB_STATE_FAILED | JOB_STATE_DONE, // listening state
				boost::bind(&state_change_listener::state_changed, &listener, _1, _2))); // callback functor
		if (error != globus::gram::no_error)
		{
			std::cerr << error << std::endl;
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
