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
include examples/hub/CMakeFiles/pub.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/hub/CMakeFiles/pub.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/hub/CMakeFiles/pub.dir/progress.make

# Include the compile flags for this target's objects.
include examples/hub/CMakeFiles/pub.dir/flags.make

examples/hub/CMakeFiles/pub.dir/pub.cc.o: examples/hub/CMakeFiles/pub.dir/flags.make
examples/hub/CMakeFiles/pub.dir/pub.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/hub/pub.cc
examples/hub/CMakeFiles/pub.dir/pub.cc.o: examples/hub/CMakeFiles/pub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/hub/CMakeFiles/pub.dir/pub.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/hub/CMakeFiles/pub.dir/pub.cc.o -MF CMakeFiles/pub.dir/pub.cc.o.d -o CMakeFiles/pub.dir/pub.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/hub/pub.cc

examples/hub/CMakeFiles/pub.dir/pub.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pub.dir/pub.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/hub/pub.cc > CMakeFiles/pub.dir/pub.cc.i

examples/hub/CMakeFiles/pub.dir/pub.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pub.dir/pub.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/hub/pub.cc -o CMakeFiles/pub.dir/pub.cc.s

# Object files for target pub
pub_OBJECTS = \
"CMakeFiles/pub.dir/pub.cc.o"

# External object files for target pub
pub_EXTERNAL_OBJECTS =

bin/pub: examples/hub/CMakeFiles/pub.dir/pub.cc.o
bin/pub: examples/hub/CMakeFiles/pub.dir/build.make
bin/pub: lib/libmuduo_pubsub.a
bin/pub: lib/libmuduo_net.a
bin/pub: lib/libmuduo_base.a
bin/pub: examples/hub/CMakeFiles/pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/pub"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/hub/CMakeFiles/pub.dir/build: bin/pub
.PHONY : examples/hub/CMakeFiles/pub.dir/build

examples/hub/CMakeFiles/pub.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub && $(CMAKE_COMMAND) -P CMakeFiles/pub.dir/cmake_clean.cmake
.PHONY : examples/hub/CMakeFiles/pub.dir/clean

examples/hub/CMakeFiles/pub.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/hub /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/hub/CMakeFiles/pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/hub/CMakeFiles/pub.dir/depend

