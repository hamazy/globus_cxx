/** -*- mode: c++; coding: utf-8; -*- 
 *@file
 *@brief
 */
#ifndef GLOBUS_CXX_COMMON_UTIL_HPP_
#define GLOBUS_CXX_COMMON_UTIL_HPP_

#include <functional>

namespace globus { namespace util {

template<typename Operation>
class on_exit
{
	Operation operation_;
	typename Operation::argument_type value_;
public:
	on_exit(Operation const &operation, typename Operation::argument_type const &value)
		: operation_(operation)
		, value_(value) {}

	virtual ~on_exit()
	{
		operation_(value_);
	}

private:
	on_exit(on_exit const &src);
	on_exit &operator=(on_exit const &src);
};

}
}

#endif // GLOBUS_CXX_COMMON_UTIL_HPP_
