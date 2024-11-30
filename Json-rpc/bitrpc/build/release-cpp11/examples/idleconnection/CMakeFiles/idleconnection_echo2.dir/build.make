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
include examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/flags.make

examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o: examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/flags.make
examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/idleconnection/sortedlist.cc
examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o: examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o -MF CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o.d -o CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/idleconnection/sortedlist.cc

examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/idleconnection/sortedlist.cc > CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.i

examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/idleconnection/sortedlist.cc -o CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.s

# Object files for target idleconnection_echo2
idleconnection_echo2_OBJECTS = \
"CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o"

# External object files for target idleconnection_echo2
idleconnection_echo2_EXTERNAL_OBJECTS =

bin/idleconnection_echo2: examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o
bin/idleconnection_echo2: examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/build.make
bin/idleconnection_echo2: lib/libmuduo_net.a
bin/idleconnection_echo2: lib/libmuduo_base.a
bin/idleconnection_echo2: examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/idleconnection_echo2"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/idleconnection_echo2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/build: bin/idleconnection_echo2
.PHONY : examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/build

examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection && $(CMAKE_COMMAND) -P CMakeFiles/idleconnection_echo2.dir/cmake_clean.cmake
.PHONY : examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/clean

examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/idleconnection /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/idleconnection/CMakeFiles/idleconnection_echo2.dir/depend

