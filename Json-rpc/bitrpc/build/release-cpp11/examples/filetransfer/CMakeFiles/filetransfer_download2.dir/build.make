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
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/filetransfer/CMakeFiles/filetransfer_download2.dir/flags.make

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/flags.make
examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o: /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/filetransfer/download2.cc
examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o -MF CMakeFiles/filetransfer_download2.dir/download2.cc.o.d -o CMakeFiles/filetransfer_download2.dir/download2.cc.o -c /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/filetransfer/download2.cc

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/filetransfer_download2.dir/download2.cc.i"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/filetransfer/download2.cc > CMakeFiles/filetransfer_download2.dir/download2.cc.i

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/filetransfer_download2.dir/download2.cc.s"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/filetransfer/download2.cc -o CMakeFiles/filetransfer_download2.dir/download2.cc.s

# Object files for target filetransfer_download2
filetransfer_download2_OBJECTS = \
"CMakeFiles/filetransfer_download2.dir/download2.cc.o"

# External object files for target filetransfer_download2
filetransfer_download2_EXTERNAL_OBJECTS =

bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/download2.cc.o
bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build.make
bin/filetransfer_download2: lib/libmuduo_net.a
bin/filetransfer_download2: lib/libmuduo_base.a
bin/filetransfer_download2: examples/filetransfer/CMakeFiles/filetransfer_download2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/filetransfer_download2"
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filetransfer_download2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build: bin/filetransfer_download2
.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/build

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/clean:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer && $(CMAKE_COMMAND) -P CMakeFiles/filetransfer_download2.dir/cmake_clean.cmake
.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/clean

examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend:
	cd /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/muduo-master/examples/filetransfer /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11 /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer /root/linux/Linux-ubantu/Json-rpc/bitrpc/third/build/release-cpp11/examples/filetransfer/CMakeFiles/filetransfer_download2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/filetransfer/CMakeFiles/filetransfer_download2.dir/depend

