/** -*- mode: c++; coding: utf-8; -*- 
 *@file
 *@brief
 */
#ifndef GLOBUS_CXX_COMMON_MODULE_HPP_
#define GLOBUS_CXX_COMMON_MODULE_HPP_

#include <sstream>

#include "globus_common.h"
#include "globus_gram_client.h"

#include "common/error.hpp"

namespace globus {

class module
{
	::globus_module_descriptor_t &module_descriptor_;
public:
	module(::globus_module_descriptor_t &module_descriptor)
		: module_descriptor_(module_descriptor)
	{
		const int result(::globus_module_activate(&module_descriptor_));
		if (result != GLOBUS_SUCCESS)
		{
			std::stringstream msg;
			msg << "module activation failed: "
				<< module_descriptor_.module_name;
			throw module_exception(msg.str());
		}
	}

	~module()
	{
		const int result(globus_module_deactivate(&module_descriptor_));
		if (result != GLOBUS_SUCCESS)
		{
			std::stringstream msg;
			msg << "module deactivation failed: "
				<< module_descriptor_.module_name;
			throw module_exception(msg.str());
		}
	}
private:
	module(module const &src);
	module &operator=(module const &src);

};

}

#endif // GLOBUS_CXX_COMMON_MODULE_HPP_
