# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11

# Include any dependencies generated for this target.
include examples/memcached/client/CMakeFiles/memcached_bench.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/memcached/client/CMakeFiles/memcached_bench.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/memcached/client/CMakeFiles/memcached_bench.dir/progress.make

# Include the compile flags for this target's objects.
include examples/memcached/client/CMakeFiles/memcached_bench.dir/flags.make

examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o: examples/memcached/client/CMakeFiles/memcached_bench.dir/flags.make
examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/memcached/client/bench.cc
examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o: examples/memcached/client/CMakeFiles/memcached_bench.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o -MF CMakeFiles/memcached_bench.dir/bench.cc.o.d -o CMakeFiles/memcached_bench.dir/bench.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/memcached/client/bench.cc

examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memcached_bench.dir/bench.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/memcached/client/bench.cc > CMakeFiles/memcached_bench.dir/bench.cc.i

examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memcached_bench.dir/bench.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/memcached/client/bench.cc -o CMakeFiles/memcached_bench.dir/bench.cc.s

# Object files for target memcached_bench
memcached_bench_OBJECTS = \
"CMakeFiles/memcached_bench.dir/bench.cc.o"

# External object files for target memcached_bench
memcached_bench_EXTERNAL_OBJECTS =

bin/memcached_bench: examples/memcached/client/CMakeFiles/memcached_bench.dir/bench.cc.o
bin/memcached_bench: examples/memcached/client/CMakeFiles/memcached_bench.dir/build.make
bin/memcached_bench: lib/libmuduo_net.a
bin/memcached_bench: lib/libmuduo_base.a
bin/memcached_bench: examples/memcached/client/CMakeFiles/memcached_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/memcached_bench"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memcached_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/memcached/client/CMakeFiles/memcached_bench.dir/build: bin/memcached_bench
.PHONY : examples/memcached/client/CMakeFiles/memcached_bench.dir/build

examples/memcached/client/CMakeFiles/memcached_bench.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client && $(CMAKE_COMMAND) -P CMakeFiles/memcached_bench.dir/cmake_clean.cmake
.PHONY : examples/memcached/client/CMakeFiles/memcached_bench.dir/clean

examples/memcached/client/CMakeFiles/memcached_bench.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/memcached/client /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/memcached/client/CMakeFiles/memcached_bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/memcached/client/CMakeFiles/memcached_bench.dir/depend

