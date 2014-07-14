ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -Iinclude -I${top_srcdir}/include

AM_CXXFLAGS = -Wall -Wextra -std=c++11
bin_PROGRAMS = uld
uld_SOURCES = src/main.cc \
			  src/driver.cc

uld_LDADD = ${top_builddir}/libucmp.la
