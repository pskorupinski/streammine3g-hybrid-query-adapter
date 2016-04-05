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

# Include any dependencies generated for this target.
include Events/CMakeFiles/Events.dir/depend.make

# Include the progress variables for this target.
include Events/CMakeFiles/Events.dir/progress.make

# Include the compile flags for this target's objects.
include Events/CMakeFiles/Events.dir/flags.make

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o: Events/CMakeFiles/Events.dir/flags.make
Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o: Event.pb.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o"
	cd /local/mt1/workspace/example-third/Events && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Events.dir/__/Event.pb.cpp.o -c /local/mt1/workspace/example-third/Event.pb.cpp

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Events.dir/__/Event.pb.cpp.i"
	cd /local/mt1/workspace/example-third/Events && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /local/mt1/workspace/example-third/Event.pb.cpp > CMakeFiles/Events.dir/__/Event.pb.cpp.i

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Events.dir/__/Event.pb.cpp.s"
	cd /local/mt1/workspace/example-third/Events && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /local/mt1/workspace/example-third/Event.pb.cpp -o CMakeFiles/Events.dir/__/Event.pb.cpp.s

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.requires:
.PHONY : Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.requires

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.provides: Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.requires
	$(MAKE) -f Events/CMakeFiles/Events.dir/build.make Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.provides.build
.PHONY : Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.provides

Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.provides.build: Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o

Event.pb.cpp: Event.pb.c1
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler (patch2) for Event..."
	cd /local/mt1/workspace/example-third/Events && sed 1i#include\ \"../src/GPBPatch.hpp\" /local/mt1/workspace/example-third/Event.pb.c1 > /local/mt1/workspace/example-third/Event.pb.cpp

Event.pb.c1: Event.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler (patch1) for Event..."
	cd /local/mt1/workspace/example-third/Events && sed 's/::google::protobuf::internal::OnShutdown/GPBPatch::InitShutdownFunctions();GPBPatch::OnShutdown/' /local/mt1/workspace/example-third/Event.pb.cc > /local/mt1/workspace/example-third/Event.pb.c1

Event.pb.cc: Events/Event.proto
	$(CMAKE_COMMAND) -E cmake_progress_report /local/mt1/workspace/example-third/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Google Protocol Buffers Compiler for Event..."
	cd /local/mt1/workspace/example-third/Events && protoc --proto_path=/local/mt1/workspace/example-third/Events --cpp_out=/local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events/Event.proto

Event.pb.h: Event.pb.cc

# Object files for target Events
Events_OBJECTS = \
"CMakeFiles/Events.dir/__/Event.pb.cpp.o"

# External object files for target Events
Events_EXTERNAL_OBJECTS =

Events/libEvents.a: Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o
Events/libEvents.a: Events/CMakeFiles/Events.dir/build.make
Events/libEvents.a: Events/CMakeFiles/Events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libEvents.a"
	cd /local/mt1/workspace/example-third/Events && $(CMAKE_COMMAND) -P CMakeFiles/Events.dir/cmake_clean_target.cmake
	cd /local/mt1/workspace/example-third/Events && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Events/CMakeFiles/Events.dir/build: Events/libEvents.a
.PHONY : Events/CMakeFiles/Events.dir/build

Events/CMakeFiles/Events.dir/requires: Events/CMakeFiles/Events.dir/__/Event.pb.cpp.o.requires
.PHONY : Events/CMakeFiles/Events.dir/requires

Events/CMakeFiles/Events.dir/clean:
	cd /local/mt1/workspace/example-third/Events && $(CMAKE_COMMAND) -P CMakeFiles/Events.dir/cmake_clean.cmake
.PHONY : Events/CMakeFiles/Events.dir/clean

Events/CMakeFiles/Events.dir/depend: Event.pb.cpp
Events/CMakeFiles/Events.dir/depend: Event.pb.c1
Events/CMakeFiles/Events.dir/depend: Event.pb.cc
Events/CMakeFiles/Events.dir/depend: Event.pb.h
	cd /local/mt1/workspace/example-third && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events /local/mt1/workspace/example-third /local/mt1/workspace/example-third/Events /local/mt1/workspace/example-third/Events/CMakeFiles/Events.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Events/CMakeFiles/Events.dir/depend

