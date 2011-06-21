/** -*- mode: c++; coding: utf-8; -*- 
 *@file
 *@brief
 */
#ifndef GLOBUS_CXX_COMMON_THREAD_HPP_
#define GLOBUS_CXX_COMMON_THREAD_HPP_

#include "globus_thread_common.h"

namespace globus { namespace thread {

template<typename Mutex>
class lock_guard
{
	Mutex &mutex_;
public:
	lock_guard(Mutex &mutex)
		: mutex_(mutex)
	{
		mutex_.lock();
	}
	virtual ~lock_guard()
	{
		mutex_.unlock();
	}
private:
	lock_guard(lock_guard const &src);
	lock_guard &operator=(lock_guard const &src);
};

class mutex
{
	friend class cond;
    globus_mutex_t mutex_;
public:
	typedef lock_guard<mutex> scoped_lock;
	mutex()
		: mutex_()
	{
		globus_mutex_init(&mutex_, NULL);
	}
	virtual ~mutex()
	{
		globus_mutex_destroy(&mutex_);
	}
	int lock()
	{
		return globus_mutex_lock(&mutex_);
	}
	int unlock()
	{
		return globus_mutex_unlock(&mutex_);
	}

private:
	mutex(mutex const &src);
	mutex &operator=(mutex const &src);

};

class cond
{
    globus_cond_t cond_;
public:
	cond()
		: cond_()
	{
		globus_cond_init(&cond_, NULL);
	}

	virtual ~cond()
	{
		globus_cond_destroy(&cond_);
	}

	void wait(mutex &mutex)
	{
		globus_cond_wait(&cond_, &mutex.mutex_);
	}

	void signal()
	{
		globus_cond_signal(&cond_);
	}

private:
	cond(cond const &src);
	cond &operator=(cond const &src);

};

}
}
#endif // GLOBUS_CXX_COMMON_THREAD_HPP_
