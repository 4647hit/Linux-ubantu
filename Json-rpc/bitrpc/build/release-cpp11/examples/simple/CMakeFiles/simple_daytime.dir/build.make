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
include examples/simple/CMakeFiles/simple_daytime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/simple/CMakeFiles/simple_daytime.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/simple/CMakeFiles/simple_daytime.dir/progress.make

# Include the compile flags for this target's objects.
include examples/simple/CMakeFiles/simple_daytime.dir/flags.make

examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o: examples/simple/CMakeFiles/simple_daytime.dir/flags.make
examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/daytime.cc
examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o: examples/simple/CMakeFiles/simple_daytime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o -MF CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o.d -o CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/daytime.cc

examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_daytime.dir/daytime/daytime.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/daytime.cc > CMakeFiles/simple_daytime.dir/daytime/daytime.cc.i

examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_daytime.dir/daytime/daytime.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/daytime.cc -o CMakeFiles/simple_daytime.dir/daytime/daytime.cc.s

examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o: examples/simple/CMakeFiles/simple_daytime.dir/flags.make
examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/main.cc
examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o: examples/simple/CMakeFiles/simple_daytime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o -MF CMakeFiles/simple_daytime.dir/daytime/main.cc.o.d -o CMakeFiles/simple_daytime.dir/daytime/main.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/main.cc

examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_daytime.dir/daytime/main.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/main.cc > CMakeFiles/simple_daytime.dir/daytime/main.cc.i

examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_daytime.dir/daytime/main.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple/daytime/main.cc -o CMakeFiles/simple_daytime.dir/daytime/main.cc.s

# Object files for target simple_daytime
simple_daytime_OBJECTS = \
"CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o" \
"CMakeFiles/simple_daytime.dir/daytime/main.cc.o"

# External object files for target simple_daytime
simple_daytime_EXTERNAL_OBJECTS =

bin/simple_daytime: examples/simple/CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o
bin/simple_daytime: examples/simple/CMakeFiles/simple_daytime.dir/daytime/main.cc.o
bin/simple_daytime: examples/simple/CMakeFiles/simple_daytime.dir/build.make
bin/simple_daytime: lib/libmuduo_net.a
bin/simple_daytime: lib/libmuduo_base.a
bin/simple_daytime: examples/simple/CMakeFiles/simple_daytime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/simple_daytime"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_daytime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/simple/CMakeFiles/simple_daytime.dir/build: bin/simple_daytime
.PHONY : examples/simple/CMakeFiles/simple_daytime.dir/build

examples/simple/CMakeFiles/simple_daytime.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple && $(CMAKE_COMMAND) -P CMakeFiles/simple_daytime.dir/cmake_clean.cmake
.PHONY : examples/simple/CMakeFiles/simple_daytime.dir/clean

examples/simple/CMakeFiles/simple_daytime.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/simple /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/simple/CMakeFiles/simple_daytime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/simple/CMakeFiles/simple_daytime.dir/depend

