# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /local/mt1/workspace/example-third

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /local/mt1/workspace/example-third

# Utility rule file for GenerateEvents.

# Include the progress variables for this target.
include Events/CMakeFiles/GenerateEvents.dir/progress.make

Events/CMakeFiles/GenerateEvents: Event.pb.cpp

Event.pb.cpp: Event.pb.c1
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler (patch2) for Event..."
	cd /local/mt1/workspace/example-third/Events && sed 1i#include\ \"../src/GPBPatch.hpp\" /local/mt1/workspace/example-third/Event.pb.c1 > /local/mt1/workspace/example-third/Event.pb.cpp

Event.pb.c1: Event.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler (patch1) for Event..."
	cd /local/mt1/workspace/example-third/Events && sed 's/::google::protobuf::internal::OnShutdown/GPBPatch::InitShutdownFunctions();GPBPatch::OnShutdown/' /local/mt1/workspace/example-third/Event.pb.cc > /local/mt1/workspace/example-third/Event.pb.c1

Event.pb.cc: Events/Event.proto
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler for Event..."
	cd /local/mt1/workspace/example-third/Events && protoc --proto_path=/local/mt1/workspace/example-third/Events --cpp_out=/local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events/Event.proto

Event.pb.h: Event.pb.cc

GenerateEvents: Events/CMakeFiles/GenerateEvents
GenerateEvents: Event.pb.cpp
GenerateEvents: Event.pb.c1
GenerateEvents: Event.pb.cc
GenerateEvents: Event.pb.h
GenerateEvents: Events/CMakeFiles/GenerateEvents.dir/build.make
.PHONY : GenerateEvents

# Rule to build all files generated by this target.
Events/CMakeFiles/GenerateEvents.dir/build: GenerateEvents
.PHONY : Events/CMakeFiles/GenerateEvents.dir/build

Events/CMakeFiles/GenerateEvents.dir/clean:
	cd /local/mt1/workspace/example-third/Events && $(CMAKE_COMMAND) -P CMakeFiles/GenerateEvents.dir/cmake_clean.cmake
.PHONY : Events/CMakeFiles/GenerateEvents.dir/clean

Events/CMakeFiles/GenerateEvents.dir/depend:
	cd /local/mt1/workspace/example-third && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events /local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events /local/mt1/workspace/example-third/Events/CMakeFiles/GenerateEvents.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Events/CMakeFiles/GenerateEvents.dir/depend

