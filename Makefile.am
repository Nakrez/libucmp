AM_CXXFLAGS = -Wall -Wextra -std=c++11
ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = -Iinclude
lib_LTLIBRARIES = libucmp.la
libucmp_la_SOURCES = lib/misc/diagnostic-reporter.cc \
					 lib/misc/indent.cc \
					 lib/misc/memory-buffer.cc \
					 lib/misc/symbol.cc \
					 lib/ir/value-map.cc \
					 lib/ir/array-type.cc \
					 lib/ir/basic-block.cc \
					 lib/ir/instruction.cc \
					 lib/ir/binary-inst.cc \
					 lib/ir/cmp.cc \
					 lib/ir/store.cc \
					 lib/ir/load.cc \
					 lib/ir/ret.cc \
					 lib/ir/jump.cc \
					 lib/ir/cjump.cc \
					 lib/ir/call.cc \
					 lib/ir/phi-node.cc \
					 lib/ir/cast.cc \
					 lib/ir/data-ptr.cc \
					 lib/ir/context.cc \
					 lib/ir/function.cc \
					 lib/ir/function-type.cc \
					 lib/ir/global-variable.cc \
					 lib/ir/value.cc \
					 lib/ir/argument.cc \
					 lib/ir/int-constant.cc \
					 lib/ir/ir-generator.cc \
					 lib/ir/struct-type.cc \
					 lib/ir/type.cc \
					 lib/ir/unit.cc \
					 lib/ir/ir-writer.cc \
					 lib/ir/pass-manager.cc \
					 lib/link/core/file.cc \
					 lib/link/core/fragment.cc \
					 lib/link/core/symbol.cc \
					 lib/link/core/symbol-table.cc \
					 lib/link/elf/elf-importer.cc

SUBDIRS= . tools
