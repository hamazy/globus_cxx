/** -*- mode: c++; coding: utf-8; -*- 
 *@file
 *@brief
 */
#ifndef GLOBUS_CXX_COMMON_ERROR_H_
#define GLOBUS_CXX_COMMON_ERROR_H_

namespace globus
{

class module_exception: public std::exception
{
	const std::string string_;
public:
	module_exception(char const *const string)
		: string_(string) {}

	module_exception(std::string const &string)
		: string_(string) {}

	virtual ~module_exception() throw() {}

	virtual char const *what() const throw()
	{
		return string_.c_str();
	}
};

}

#endif // GLOBUS_CXX_COMMON_ERROR_H_
