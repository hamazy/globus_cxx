INCLUDES = -I$(top_builddir)

noinst_PROGRAMS = \
	gram_ping_example  \
	gram_submit_example \
	gram_async_submit_example
# gram_submit_and_wait_example \
# gram_poll_example \
# gram_refresh_example \
# gram_rsl_example \
# gram_attr_example \
# gram_cancel_example

gram_ping_example_SOURCES = gram_ping_example.cpp
# gram_version_example_SOURCES = gram_version_example.cpp
gram_submit_example_SOURCES = gram_submit_example.cpp
# gram_submit_and_wait_example_SOURCES = gram_submit_and_wait_example.cpp
# gram_poll_example_SOURCES = gram_poll_example.cpp
# gram_refresh_example_SOURCES = gram_refresh_example.cpp
gram_async_submit_example_SOURCES = gram_async_submit_example.cpp
# gram_rsl_example_SOURCES = gram_rsl_example.cpp
# gram_attr_example_SOURCES = gram_attr_example.cpp
# gram_cancel_example_SOURCES = gram_cancel_example.cpp

check-syntax:
	$(CXXCOMPILE) -Wall -Wextra -Weffc++ -pedantic -fsyntax-only $(CHK_SOURCES)
.PHONY: check-syntax
