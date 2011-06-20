#include <iostream>
#include <string>

#include "common/module.hpp"
#include "gram/client.hpp"

int main(const int argc, char const *const argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " RESOURCE-MANAGER-CONTACT" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		globus::module gram_client_module(*GLOBUS_GRAM_CLIENT_MODULE);

		globus::gram::resource_manager_contact contact(argv[1]);
		globus::gram::client client(contact);
		globus::gram::error_code const error(client.ping()); // synchronous call

		if (error)
		{
			std::cerr << globus::gram::error(error) << std::endl;
			return EXIT_FAILURE;
		}

		std::string const version(client.jobmanager_version());
		if (version.empty())
		{
			std::cerr << "failed to get version string of job manager." << std::endl;
			return EXIT_FAILURE;
		}
		std::cout << version << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
