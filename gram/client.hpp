/** -*- mode: c++; coding: utf-8; -*- 
 *@file
 *@brief
 */
#ifndef GLOBUS_CXX_GRAM_CLIENT_HPP_
#define GLOBUS_CXX_GRAM_CLIENT_HPP_

#include <functional>

#include "globus_gram_client.h"
#include "globus_gram_protocol.h"

#include "common/util.hpp"

namespace globus { namespace gram {

enum error_code
{
	no_error = GLOBUS_SUCCESS,
    PARAMETER_NOT_SUPPORTED = GLOBUS_GRAM_PROTOCOL_ERROR_PARAMETER_NOT_SUPPORTED,
    INVALID_REQUEST = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_REQUEST,
    NO_RESOURCES = GLOBUS_GRAM_PROTOCOL_ERROR_NO_RESOURCES,
    BAD_DIRECTORY = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_DIRECTORY,
    EXECUTABLE_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_EXECUTABLE_NOT_FOUND,
    INSUFFICIENT_FUNDS = GLOBUS_GRAM_PROTOCOL_ERROR_INSUFFICIENT_FUNDS,
    AUTHORIZATION = GLOBUS_GRAM_PROTOCOL_ERROR_AUTHORIZATION,
    USER_CANCELLED = GLOBUS_GRAM_PROTOCOL_ERROR_USER_CANCELLED,
    SYSTEM_CANCELLED = GLOBUS_GRAM_PROTOCOL_ERROR_SYSTEM_CANCELLED,
    PROTOCOL_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_PROTOCOL_FAILED,
    STDIN_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_STDIN_NOT_FOUND,
    CONNECTION_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_CONNECTION_FAILED,
    INVALID_MAXTIME = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_MAXTIME,
    INVALID_COUNT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_COUNT,
    NULL_SPECIFICATION_TREE = GLOBUS_GRAM_PROTOCOL_ERROR_NULL_SPECIFICATION_TREE,
    JM_FAILED_ALLOW_ATTACH = GLOBUS_GRAM_PROTOCOL_ERROR_JM_FAILED_ALLOW_ATTACH,
    JOB_EXECUTION_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_JOB_EXECUTION_FAILED,
    INVALID_PARADYN = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_PARADYN,
    INVALID_JOBTYPE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_JOBTYPE,
    INVALID_GRAM_MYJOB = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_GRAM_MYJOB,
    BAD_SCRIPT_ARG_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_SCRIPT_ARG_FILE,
    ARG_FILE_CREATION_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_ARG_FILE_CREATION_FAILED,
    INVALID_JOBSTATE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_JOBSTATE,
    INVALID_SCRIPT_REPLY = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SCRIPT_REPLY,
    INVALID_SCRIPT_STATUS = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SCRIPT_STATUS,
    JOBTYPE_NOT_SUPPORTED = GLOBUS_GRAM_PROTOCOL_ERROR_JOBTYPE_NOT_SUPPORTED,
    UNIMPLEMENTED = GLOBUS_GRAM_PROTOCOL_ERROR_UNIMPLEMENTED,
    TEMP_SCRIPT_FILE_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_TEMP_SCRIPT_FILE_FAILED,
    USER_PROXY_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_USER_PROXY_NOT_FOUND,
    OPENING_USER_PROXY = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_USER_PROXY,
    JOB_CANCEL_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_JOB_CANCEL_FAILED,
    MALLOC_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_MALLOC_FAILED,
    DUCT_INIT_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_DUCT_INIT_FAILED,
    DUCT_LSP_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_DUCT_LSP_FAILED,
    INVALID_HOST_COUNT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_HOST_COUNT,
    UNSUPPORTED_PARAMETER = GLOBUS_GRAM_PROTOCOL_ERROR_UNSUPPORTED_PARAMETER,
    INVALID_QUEUE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_QUEUE,
    INVALID_PROJECT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_PROJECT,
    RSL_EVALUATION_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_EVALUATION_FAILED,
    BAD_RSL_ENVIRONMENT = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_RSL_ENVIRONMENT,
    DRYRUN = GLOBUS_GRAM_PROTOCOL_ERROR_DRYRUN,
    ZERO_LENGTH_RSL = GLOBUS_GRAM_PROTOCOL_ERROR_ZERO_LENGTH_RSL,
    STAGING_EXECUTABLE = GLOBUS_GRAM_PROTOCOL_ERROR_STAGING_EXECUTABLE,
    STAGING_STDIN = GLOBUS_GRAM_PROTOCOL_ERROR_STAGING_STDIN,
    INVALID_JOB_MANAGER_TYPE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_JOB_MANAGER_TYPE,
    BAD_ARGUMENTS = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_ARGUMENTS,
    GATEKEEPER_MISCONFIGURED = GLOBUS_GRAM_PROTOCOL_ERROR_GATEKEEPER_MISCONFIGURED,
    BAD_RSL = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_RSL,
    VERSION_MISMATCH = GLOBUS_GRAM_PROTOCOL_ERROR_VERSION_MISMATCH,
    RSL_ARGUMENTS = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_ARGUMENTS,
    RSL_COUNT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_COUNT,
    RSL_DIRECTORY = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_DIRECTORY,
    RSL_DRYRUN = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_DRYRUN,
    RSL_ENVIRONMENT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_ENVIRONMENT,
    RSL_EXECUTABLE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_EXECUTABLE,
    RSL_HOST_COUNT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_HOST_COUNT,
    RSL_JOBTYPE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_JOBTYPE,
    RSL_MAXTIME = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MAXTIME,
    RSL_MYJOB = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MYJOB,
    RSL_PARADYN = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_PARADYN,
    RSL_PROJECT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_PROJECT,
    RSL_QUEUE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_QUEUE,
    RSL_STDERR = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_STDERR,
    RSL_STDIN = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_STDIN,
    RSL_STDOUT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_STDOUT,
    OPENING_JOBMANAGER_SCRIPT = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_JOBMANAGER_SCRIPT,
    CREATING_PIPE = GLOBUS_GRAM_PROTOCOL_ERROR_CREATING_PIPE,
    FCNTL_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_FCNTL_FAILED,
    STDOUT_FILENAME_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_STDOUT_FILENAME_FAILED,
    STDERR_FILENAME_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_STDERR_FILENAME_FAILED,
    FORKING_EXECUTABLE = GLOBUS_GRAM_PROTOCOL_ERROR_FORKING_EXECUTABLE,
    EXECUTABLE_PERMISSIONS = GLOBUS_GRAM_PROTOCOL_ERROR_EXECUTABLE_PERMISSIONS,
    OPENING_STDOUT = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_STDOUT,
    OPENING_STDERR = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_STDERR,
    OPENING_CACHE_USER_PROXY = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_CACHE_USER_PROXY,
    OPENING_CACHE = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_CACHE,
    INSERTING_CLIENT_CONTACT = GLOBUS_GRAM_PROTOCOL_ERROR_INSERTING_CLIENT_CONTACT,
    CLIENT_CONTACT_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_CLIENT_CONTACT_NOT_FOUND,
    CONTACTING_JOB_MANAGER = GLOBUS_GRAM_PROTOCOL_ERROR_CONTACTING_JOB_MANAGER,
    INVALID_JOB_CONTACT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_JOB_CONTACT,
    UNDEFINED_EXE = GLOBUS_GRAM_PROTOCOL_ERROR_UNDEFINED_EXE,
    CONDOR_ARCH = GLOBUS_GRAM_PROTOCOL_ERROR_CONDOR_ARCH,
    CONDOR_OS = GLOBUS_GRAM_PROTOCOL_ERROR_CONDOR_OS,
    RSL_MIN_MEMORY = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MIN_MEMORY,
    RSL_MAX_MEMORY = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MAX_MEMORY,
    INVALID_MIN_MEMORY = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_MIN_MEMORY,
    INVALID_MAX_MEMORY = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_MAX_MEMORY,
    HTTP_FRAME_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_HTTP_FRAME_FAILED,
    HTTP_UNFRAME_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_HTTP_UNFRAME_FAILED,
    HTTP_PACK_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_HTTP_PACK_FAILED,
    HTTP_UNPACK_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_HTTP_UNPACK_FAILED,
    INVALID_JOB_QUERY = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_JOB_QUERY,
    SERVICE_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_SERVICE_NOT_FOUND,
    JOB_QUERY_DENIAL = GLOBUS_GRAM_PROTOCOL_ERROR_JOB_QUERY_DENIAL,
    CALLBACK_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_CALLBACK_NOT_FOUND,
    BAD_GATEKEEPER_CONTACT = GLOBUS_GRAM_PROTOCOL_ERROR_BAD_GATEKEEPER_CONTACT,
    POE_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_POE_NOT_FOUND,
    MPIRUN_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_MPIRUN_NOT_FOUND,
    RSL_START_TIME = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_START_TIME,
    RSL_RESERVATION_HANDLE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_RESERVATION_HANDLE,
    RSL_MAX_WALL_TIME = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MAX_WALL_TIME,
    INVALID_MAX_WALL_TIME = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_MAX_WALL_TIME,
    RSL_MAX_CPU_TIME = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_MAX_CPU_TIME,
    INVALID_MAX_CPU_TIME = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_MAX_CPU_TIME,
    JM_SCRIPT_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_JM_SCRIPT_NOT_FOUND,
    JM_SCRIPT_PERMISSIONS = GLOBUS_GRAM_PROTOCOL_ERROR_JM_SCRIPT_PERMISSIONS,
    SIGNALING_JOB = GLOBUS_GRAM_PROTOCOL_ERROR_SIGNALING_JOB,
    UNKNOWN_SIGNAL_TYPE = GLOBUS_GRAM_PROTOCOL_ERROR_UNKNOWN_SIGNAL_TYPE,
    GETTING_JOBID = GLOBUS_GRAM_PROTOCOL_ERROR_GETTING_JOBID,
    WAITING_FOR_COMMIT = GLOBUS_GRAM_PROTOCOL_ERROR_WAITING_FOR_COMMIT,
    COMMIT_TIMED_OUT = GLOBUS_GRAM_PROTOCOL_ERROR_COMMIT_TIMED_OUT,
    RSL_SAVE_STATE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_SAVE_STATE,
    RSL_RESTART = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_RESTART,
    RSL_TWO_PHASE_COMMIT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_TWO_PHASE_COMMIT,
    INVALID_TWO_PHASE_COMMIT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_TWO_PHASE_COMMIT,
    RSL_STDOUT_POSITION = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_STDOUT_POSITION,
    INVALID_STDOUT_POSITION = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_STDOUT_POSITION,
    RSL_STDERR_POSITION = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_STDERR_POSITION,
    INVALID_STDERR_POSITION = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_STDERR_POSITION,
    RESTART_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_RESTART_FAILED,
    NO_STATE_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_NO_STATE_FILE,
    READING_STATE_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_READING_STATE_FILE,
    WRITING_STATE_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_WRITING_STATE_FILE,
    OLD_JM_ALIVE = GLOBUS_GRAM_PROTOCOL_ERROR_OLD_JM_ALIVE,
    TTL_EXPIRED = GLOBUS_GRAM_PROTOCOL_ERROR_TTL_EXPIRED,
    SUBMIT_UNKNOWN = GLOBUS_GRAM_PROTOCOL_ERROR_SUBMIT_UNKNOWN,
    RSL_REMOTE_IO_URL = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_REMOTE_IO_URL,
    WRITING_REMOTE_IO_URL = GLOBUS_GRAM_PROTOCOL_ERROR_WRITING_REMOTE_IO_URL,
    STDIO_SIZE = GLOBUS_GRAM_PROTOCOL_ERROR_STDIO_SIZE,
    JM_STOPPED = GLOBUS_GRAM_PROTOCOL_ERROR_JM_STOPPED,
    USER_PROXY_EXPIRED = GLOBUS_GRAM_PROTOCOL_ERROR_USER_PROXY_EXPIRED,
    JOB_UNSUBMITTED = GLOBUS_GRAM_PROTOCOL_ERROR_JOB_UNSUBMITTED,
    INVALID_COMMIT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_COMMIT,
    RSL_SCHEDULER_SPECIFIC = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_SCHEDULER_SPECIFIC,
    STAGE_IN_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_STAGE_IN_FAILED,
    INVALID_SCRATCH = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SCRATCH,
    RSL_CACHE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_CACHE,
    INVALID_SUBMIT_ATTRIBUTE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SUBMIT_ATTRIBUTE,
    INVALID_STDIO_UPDATE_ATTRIBUTE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_STDIO_UPDATE_ATTRIBUTE,
    INVALID_RESTART_ATTRIBUTE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_RESTART_ATTRIBUTE,
    RSL_FILE_STAGE_IN = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_FILE_STAGE_IN,
    RSL_FILE_STAGE_IN_SHARED = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_FILE_STAGE_IN_SHARED,
    RSL_FILE_STAGE_OUT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_FILE_STAGE_OUT,
    RSL_GASS_CACHE = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_GASS_CACHE,
    RSL_FILE_CLEANUP = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_FILE_CLEANUP,
    RSL_SCRATCH = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_SCRATCH,
    INVALID_SCHEDULER_SPECIFIC = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SCHEDULER_SPECIFIC,
    UNDEFINED_ATTRIBUTE = GLOBUS_GRAM_PROTOCOL_ERROR_UNDEFINED_ATTRIBUTE,
    INVALID_CACHE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_CACHE,
    INVALID_SAVE_STATE = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_SAVE_STATE,
    OPENING_VALIDATION_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_OPENING_VALIDATION_FILE,
    READING_VALIDATION_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_READING_VALIDATION_FILE,
    RSL_PROXY_TIMEOUT = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_PROXY_TIMEOUT,
    INVALID_PROXY_TIMEOUT = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_PROXY_TIMEOUT,
    STAGE_OUT_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_STAGE_OUT_FAILED,
    JOB_CONTACT_NOT_FOUND = GLOBUS_GRAM_PROTOCOL_ERROR_JOB_CONTACT_NOT_FOUND,
    DELEGATION_FAILED = GLOBUS_GRAM_PROTOCOL_ERROR_DELEGATION_FAILED,
    LOCKING_STATE_LOCK_FILE = GLOBUS_GRAM_PROTOCOL_ERROR_LOCKING_STATE_LOCK_FILE,
    INVALID_ATTR = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_ATTR,
    NULL_PARAMETER = GLOBUS_GRAM_PROTOCOL_ERROR_NULL_PARAMETER,
    STILL_STREAMING = GLOBUS_GRAM_PROTOCOL_ERROR_STILL_STREAMING,
    AUTHORIZATION_DENIED = GLOBUS_GRAM_PROTOCOL_ERROR_AUTHORIZATION_DENIED,
    AUTHORIZATION_SYSTEM_FAILURE = GLOBUS_GRAM_PROTOCOL_ERROR_AUTHORIZATION_SYSTEM_FAILURE,
    AUTHORIZATION_DENIED_JOB_ID = GLOBUS_GRAM_PROTOCOL_ERROR_AUTHORIZATION_DENIED_JOB_ID,
    AUTHORIZATION_DENIED_EXECUTABLE = GLOBUS_GRAM_PROTOCOL_ERROR_AUTHORIZATION_DENIED_EXECUTABLE,
    RSL_USER_NAME = GLOBUS_GRAM_PROTOCOL_ERROR_RSL_USER_NAME,
    INVALID_USER_NAME = GLOBUS_GRAM_PROTOCOL_ERROR_INVALID_USER_NAME,
};

class resource_manager_contact
{
	const std::string contact_;
public:
	resource_manager_contact(const std::string &contact)
		: contact_(contact) {}

	resource_manager_contact(char const *const contact)
		: contact_(contact) {}

	resource_manager_contact(resource_manager_contact const &src)
		: contact_(src.contact_) {}

	char const *const to_string() const
	{
		return contact_.c_str();
	}
};

class error
{
	error_code code_;
public:
	error()
		: code_(no_error) {}

	error(error_code code)
		: code_(code) {}

	error(error const &src)
		: code_(src.code_) {}

	error &operator=(error const &src)
	{
		if (this == &src) return *this;
		code_ = src.code_;
		return *this;
	}

	bool operator==(error_code code) const
	{
		return code_ == code;
	}

	bool operator!=(error_code code) const
	{
		return !operator==(code);
	}

	bool operator!() const
	{
		return code_ != no_error;
	}

	char const *const to_string() const
	{
		return ::globus_gram_client_error_string(code_);
	}
};

std::ostream &operator<<(std::ostream &stream, error const &exception)
{
	stream << exception.to_string();
	return stream;
}

class client
{
	resource_manager_contact const contact_;
public:
	client(resource_manager_contact const &contact)
		:contact_(contact) {}

	virtual ~client() {}

	error_code ping() const
	{
		return static_cast<error_code>(::globus_gram_client_ping(contact_.to_string()));
	}

	std::string jobmanager_version() const
	{
		globus_hashtable_t extensions(0);
		const int result(
			::globus_gram_client_get_jobmanager_version(
				contact_.to_string(), &extensions));

		typedef std::pointer_to_unary_function< ::globus_hashtable_t *,void> function_type;
		globus::util::on_exit<function_type> destruction(
		 	std::ptr_fun(::globus_gram_protocol_hash_destroy), &extensions);

		if (result != GLOBUS_SUCCESS) return std::string();
		::globus_gram_protocol_extension_t const *extension_value =
			  reinterpret_cast< ::globus_gram_protocol_extension_t *>(
				  ::globus_hashtable_lookup(
					  &extensions,
					  const_cast<char *>("toolkit-version")));
		if (extension_value == 0) return std::string();
		std::string const toolkit_version(extension_value->value);

		extension_value =
			reinterpret_cast< ::globus_gram_protocol_extension_t *>(
				::globus_hashtable_lookup(
					&extensions,
					const_cast<char *>("version")));
		if(extension_value->value == 0) return toolkit_version;
		std::string const gram_version(extension_value->value);

		return toolkit_version + " " + gram_version;
	}

private:
	client();
	client(client const &src);
	client &operator=(client const &src);

};

} // namespace gram
} // namespace globus

#endif // GLOBUS_CXX_GRAM_CLIENT_HPP_
