#include <iostream>

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
		globus::gram::error_code error = globus::gram::no_error;
		globus::gram::client::ping(
			globus::gram::resource_manager_contact(argv[1]), error); // synchronous call

		if (error)
		{
			std::cerr << globus::gram::error(error).to_string() << std::endl;
			return EXIT_FAILURE;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
