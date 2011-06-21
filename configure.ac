#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([globus_cxx], [0.1])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([test/gram/gram_ping_example.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB([globus_gram_client_gcc32dbg], [main])
AC_CHECK_LIB([globus_common_gcc32dbg], [main])
AC_CHECK_LIB([globus_gram_protocol_gcc32dbg], [main])
AC_CHECK_LIB([globus_rsl_gcc32dbg], [main])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

CFLAGS="-m32 $CFLAGS"
CXXFLAGS="-m32 $CXXFLAGS"

AC_CONFIG_FILES([Makefile
                 common/Makefile
                 gram/Makefile
                 test/Makefile
                 test/gram/Makefile])
AC_OUTPUT
