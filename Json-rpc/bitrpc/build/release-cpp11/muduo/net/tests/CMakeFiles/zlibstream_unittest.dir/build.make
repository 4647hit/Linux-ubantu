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
include muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/compiler_depend.make

# Include the progress variables for this target.
include muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/flags.make

muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o: muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/flags.make
muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/muduo/net/tests/ZlibStream_unittest.cc
muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o: muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o -MF CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o.d -o CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/muduo/net/tests/ZlibStream_unittest.cc

muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/muduo/net/tests/ZlibStream_unittest.cc > CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.i

muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/muduo/net/tests/ZlibStream_unittest.cc -o CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.s

# Object files for target zlibstream_unittest
zlibstream_unittest_OBJECTS = \
"CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o"

# External object files for target zlibstream_unittest
zlibstream_unittest_EXTERNAL_OBJECTS =

bin/zlibstream_unittest: muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o
bin/zlibstream_unittest: muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/build.make
bin/zlibstream_unittest: lib/libmuduo_net.a
bin/zlibstream_unittest: lib/libmuduo_base.a
bin/zlibstream_unittest: muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/zlibstream_unittest"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zlibstream_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/build: bin/zlibstream_unittest
.PHONY : muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/build

muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests && $(CMAKE_COMMAND) -P CMakeFiles/zlibstream_unittest.dir/cmake_clean.cmake
.PHONY : muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/clean

muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/muduo/net/tests /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : muduo/net/tests/CMakeFiles/zlibstream_unittest.dir/depend
