# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /local/mt1/workspace/example-third/CMakeFiles /local/mt1/workspace/example-third/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /local/mt1/workspace/example-third/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Accessop

# Build rule for target.
Accessop: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Accessop
.PHONY : Accessop

# fast build rule for target.
Accessop/fast:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/build
.PHONY : Accessop/fast

#=============================================================================
# Target rules for targets named ClientSocket

# Build rule for target.
ClientSocket: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ClientSocket
.PHONY : ClientSocket

# fast build rule for target.
ClientSocket/fast:
	$(MAKE) -f CMakeFiles/ClientSocket.dir/build.make CMakeFiles/ClientSocket.dir/build
.PHONY : ClientSocket/fast

#=============================================================================
# Target rules for targets named EndOfStreamHandler

# Build rule for target.
EndOfStreamHandler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 EndOfStreamHandler
.PHONY : EndOfStreamHandler

# fast build rule for target.
EndOfStreamHandler/fast:
	$(MAKE) -f CMakeFiles/EndOfStreamHandler.dir/build.make CMakeFiles/EndOfStreamHandler.dir/build
.PHONY : EndOfStreamHandler/fast

#=============================================================================
# Target rules for targets named Mapper

# Build rule for target.
Mapper: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Mapper
.PHONY : Mapper

# fast build rule for target.
Mapper/fast:
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/build
.PHONY : Mapper/fast

#=============================================================================
# Target rules for targets named MongoDbDataSourceAdapter

# Build rule for target.
MongoDbDataSourceAdapter: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MongoDbDataSourceAdapter
.PHONY : MongoDbDataSourceAdapter

# fast build rule for target.
MongoDbDataSourceAdapter/fast:
	$(MAKE) -f CMakeFiles/MongoDbDataSourceAdapter.dir/build.make CMakeFiles/MongoDbDataSourceAdapter.dir/build
.PHONY : MongoDbDataSourceAdapter/fast

#=============================================================================
# Target rules for targets named MyGridFS

# Build rule for target.
MyGridFS: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MyGridFS
.PHONY : MyGridFS

# fast build rule for target.
MyGridFS/fast:
	$(MAKE) -f CMakeFiles/MyGridFS.dir/build.make CMakeFiles/MyGridFS.dir/build
.PHONY : MyGridFS/fast

#=============================================================================
# Target rules for targets named Operations

# Build rule for target.
Operations: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Operations
.PHONY : Operations

# fast build rule for target.
Operations/fast:
	$(MAKE) -f CMakeFiles/Operations.dir/build.make CMakeFiles/Operations.dir/build
.PHONY : Operations/fast

#=============================================================================
# Target rules for targets named RealTimeDataSourceAdapter

# Build rule for target.
RealTimeDataSourceAdapter: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RealTimeDataSourceAdapter
.PHONY : RealTimeDataSourceAdapter

# fast build rule for target.
RealTimeDataSourceAdapter/fast:
	$(MAKE) -f CMakeFiles/RealTimeDataSourceAdapter.dir/build.make CMakeFiles/RealTimeDataSourceAdapter.dir/build
.PHONY : RealTimeDataSourceAdapter/fast

#=============================================================================
# Target rules for targets named SMByteArrayHeader

# Build rule for target.
SMByteArrayHeader: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SMByteArrayHeader
.PHONY : SMByteArrayHeader

# fast build rule for target.
SMByteArrayHeader/fast:
	$(MAKE) -f CMakeFiles/SMByteArrayHeader.dir/build.make CMakeFiles/SMByteArrayHeader.dir/build
.PHONY : SMByteArrayHeader/fast

#=============================================================================
# Target rules for targets named SMOperatorInitParam

# Build rule for target.
SMOperatorInitParam: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SMOperatorInitParam
.PHONY : SMOperatorInitParam

# fast build rule for target.
SMOperatorInitParam/fast:
	$(MAKE) -f CMakeFiles/SMOperatorInitParam.dir/build.make CMakeFiles/SMOperatorInitParam.dir/build
.PHONY : SMOperatorInitParam/fast

#=============================================================================
# Target rules for targets named SamplePartitioner

# Build rule for target.
SamplePartitioner: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SamplePartitioner
.PHONY : SamplePartitioner

# fast build rule for target.
SamplePartitioner/fast:
	$(MAKE) -f CMakeFiles/SamplePartitioner.dir/build.make CMakeFiles/SamplePartitioner.dir/build
.PHONY : SamplePartitioner/fast

#=============================================================================
# Target rules for targets named Workerop

# Build rule for target.
Workerop: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Workerop
.PHONY : Workerop

# fast build rule for target.
Workerop/fast:
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/build
.PHONY : Workerop/fast

#=============================================================================
# Target rules for targets named Events

# Build rule for target.
Events: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Events
.PHONY : Events

# fast build rule for target.
Events/fast:
	$(MAKE) -f Events/CMakeFiles/Events.dir/build.make Events/CMakeFiles/Events.dir/build
.PHONY : Events/fast

#=============================================================================
# Target rules for targets named GenerateEvents

# Build rule for target.
GenerateEvents: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GenerateEvents
.PHONY : GenerateEvents

# fast build rule for target.
GenerateEvents/fast:
	$(MAKE) -f Events/CMakeFiles/GenerateEvents.dir/build.make Events/CMakeFiles/GenerateEvents.dir/build
.PHONY : GenerateEvents/fast

src/DataSourceAdapter/MongoDbDataSourceAdapter.o: src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.o
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.o

# target to build an object file
src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.o:
	$(MAKE) -f CMakeFiles/MongoDbDataSourceAdapter.dir/build.make CMakeFiles/MongoDbDataSourceAdapter.dir/src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.o
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.o

src/DataSourceAdapter/MongoDbDataSourceAdapter.i: src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.i
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.i

# target to preprocess a source file
src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.i:
	$(MAKE) -f CMakeFiles/MongoDbDataSourceAdapter.dir/build.make CMakeFiles/MongoDbDataSourceAdapter.dir/src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.i
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.i

src/DataSourceAdapter/MongoDbDataSourceAdapter.s: src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.s
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.s

# target to generate assembly for a file
src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.s:
	$(MAKE) -f CMakeFiles/MongoDbDataSourceAdapter.dir/build.make CMakeFiles/MongoDbDataSourceAdapter.dir/src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.s
.PHONY : src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp.s

src/DataSourceAdapter/RealTimeDataSourceAdapter.o: src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.o
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.o

# target to build an object file
src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.o:
	$(MAKE) -f CMakeFiles/RealTimeDataSourceAdapter.dir/build.make CMakeFiles/RealTimeDataSourceAdapter.dir/src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.o
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.o

src/DataSourceAdapter/RealTimeDataSourceAdapter.i: src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.i
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.i

# target to preprocess a source file
src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.i:
	$(MAKE) -f CMakeFiles/RealTimeDataSourceAdapter.dir/build.make CMakeFiles/RealTimeDataSourceAdapter.dir/src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.i
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.i

src/DataSourceAdapter/RealTimeDataSourceAdapter.s: src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.s
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.s

# target to generate assembly for a file
src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.s:
	$(MAKE) -f CMakeFiles/RealTimeDataSourceAdapter.dir/build.make CMakeFiles/RealTimeDataSourceAdapter.dir/src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.s
.PHONY : src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp.s

src/SamplePartitioner.o: src/SamplePartitioner.cpp.o
.PHONY : src/SamplePartitioner.o

# target to build an object file
src/SamplePartitioner.cpp.o:
	$(MAKE) -f CMakeFiles/SamplePartitioner.dir/build.make CMakeFiles/SamplePartitioner.dir/src/SamplePartitioner.cpp.o
.PHONY : src/SamplePartitioner.cpp.o

src/SamplePartitioner.i: src/SamplePartitioner.cpp.i
.PHONY : src/SamplePartitioner.i

# target to preprocess a source file
src/SamplePartitioner.cpp.i:
	$(MAKE) -f CMakeFiles/SamplePartitioner.dir/build.make CMakeFiles/SamplePartitioner.dir/src/SamplePartitioner.cpp.i
.PHONY : src/SamplePartitioner.cpp.i

src/SamplePartitioner.s: src/SamplePartitioner.cpp.s
.PHONY : src/SamplePartitioner.s

# target to generate assembly for a file
src/SamplePartitioner.cpp.s:
	$(MAKE) -f CMakeFiles/SamplePartitioner.dir/build.make CMakeFiles/SamplePartitioner.dir/src/SamplePartitioner.cpp.s
.PHONY : src/SamplePartitioner.cpp.s

src/gridfs/MyGridFS.o: src/gridfs/MyGridFS.cpp.o
.PHONY : src/gridfs/MyGridFS.o

# target to build an object file
src/gridfs/MyGridFS.cpp.o:
	$(MAKE) -f CMakeFiles/MyGridFS.dir/build.make CMakeFiles/MyGridFS.dir/src/gridfs/MyGridFS.cpp.o
.PHONY : src/gridfs/MyGridFS.cpp.o

src/gridfs/MyGridFS.i: src/gridfs/MyGridFS.cpp.i
.PHONY : src/gridfs/MyGridFS.i

# target to preprocess a source file
src/gridfs/MyGridFS.cpp.i:
	$(MAKE) -f CMakeFiles/MyGridFS.dir/build.make CMakeFiles/MyGridFS.dir/src/gridfs/MyGridFS.cpp.i
.PHONY : src/gridfs/MyGridFS.cpp.i

src/gridfs/MyGridFS.s: src/gridfs/MyGridFS.cpp.s
.PHONY : src/gridfs/MyGridFS.s

# target to generate assembly for a file
src/gridfs/MyGridFS.cpp.s:
	$(MAKE) -f CMakeFiles/MyGridFS.dir/build.make CMakeFiles/MyGridFS.dir/src/gridfs/MyGridFS.cpp.s
.PHONY : src/gridfs/MyGridFS.cpp.s

src/operations/EndOfStreamHandler.o: src/operations/EndOfStreamHandler.cpp.o
.PHONY : src/operations/EndOfStreamHandler.o

# target to build an object file
src/operations/EndOfStreamHandler.cpp.o:
	$(MAKE) -f CMakeFiles/EndOfStreamHandler.dir/build.make CMakeFiles/EndOfStreamHandler.dir/src/operations/EndOfStreamHandler.cpp.o
.PHONY : src/operations/EndOfStreamHandler.cpp.o

src/operations/EndOfStreamHandler.i: src/operations/EndOfStreamHandler.cpp.i
.PHONY : src/operations/EndOfStreamHandler.i

# target to preprocess a source file
src/operations/EndOfStreamHandler.cpp.i:
	$(MAKE) -f CMakeFiles/EndOfStreamHandler.dir/build.make CMakeFiles/EndOfStreamHandler.dir/src/operations/EndOfStreamHandler.cpp.i
.PHONY : src/operations/EndOfStreamHandler.cpp.i

src/operations/EndOfStreamHandler.s: src/operations/EndOfStreamHandler.cpp.s
.PHONY : src/operations/EndOfStreamHandler.s

# target to generate assembly for a file
src/operations/EndOfStreamHandler.cpp.s:
	$(MAKE) -f CMakeFiles/EndOfStreamHandler.dir/build.make CMakeFiles/EndOfStreamHandler.dir/src/operations/EndOfStreamHandler.cpp.s
.PHONY : src/operations/EndOfStreamHandler.cpp.s

src/operations/operations.o: src/operations/operations.cpp.o
.PHONY : src/operations/operations.o

# target to build an object file
src/operations/operations.cpp.o:
	$(MAKE) -f CMakeFiles/Operations.dir/build.make CMakeFiles/Operations.dir/src/operations/operations.cpp.o
.PHONY : src/operations/operations.cpp.o

src/operations/operations.i: src/operations/operations.cpp.i
.PHONY : src/operations/operations.i

# target to preprocess a source file
src/operations/operations.cpp.i:
	$(MAKE) -f CMakeFiles/Operations.dir/build.make CMakeFiles/Operations.dir/src/operations/operations.cpp.i
.PHONY : src/operations/operations.cpp.i

src/operations/operations.s: src/operations/operations.cpp.s
.PHONY : src/operations/operations.s

# target to generate assembly for a file
src/operations/operations.cpp.s:
	$(MAKE) -f CMakeFiles/Operations.dir/build.make CMakeFiles/Operations.dir/src/operations/operations.cpp.s
.PHONY : src/operations/operations.cpp.s

src/operators/Accessop.o: src/operators/Accessop.cpp.o
.PHONY : src/operators/Accessop.o

# target to build an object file
src/operators/Accessop.cpp.o:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/Accessop.cpp.o
.PHONY : src/operators/Accessop.cpp.o

src/operators/Accessop.i: src/operators/Accessop.cpp.i
.PHONY : src/operators/Accessop.i

# target to preprocess a source file
src/operators/Accessop.cpp.i:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/Accessop.cpp.i
.PHONY : src/operators/Accessop.cpp.i

src/operators/Accessop.s: src/operators/Accessop.cpp.s
.PHONY : src/operators/Accessop.s

# target to generate assembly for a file
src/operators/Accessop.cpp.s:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/Accessop.cpp.s
.PHONY : src/operators/Accessop.cpp.s

src/operators/Mapper.o: src/operators/Mapper.cpp.o
.PHONY : src/operators/Mapper.o

# target to build an object file
src/operators/Mapper.cpp.o:
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/Mapper.cpp.o
.PHONY : src/operators/Mapper.cpp.o

src/operators/Mapper.i: src/operators/Mapper.cpp.i
.PHONY : src/operators/Mapper.i

# target to preprocess a source file
src/operators/Mapper.cpp.i:
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/Mapper.cpp.i
.PHONY : src/operators/Mapper.cpp.i

src/operators/Mapper.s: src/operators/Mapper.cpp.s
.PHONY : src/operators/Mapper.s

# target to generate assembly for a file
src/operators/Mapper.cpp.s:
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/Mapper.cpp.s
.PHONY : src/operators/Mapper.cpp.s

src/operators/OperatorImpl.o: src/operators/OperatorImpl.cpp.o
.PHONY : src/operators/OperatorImpl.o

# target to build an object file
src/operators/OperatorImpl.cpp.o:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/OperatorImpl.cpp.o
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/OperatorImpl.cpp.o
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/OperatorImpl.cpp.o
.PHONY : src/operators/OperatorImpl.cpp.o

src/operators/OperatorImpl.i: src/operators/OperatorImpl.cpp.i
.PHONY : src/operators/OperatorImpl.i

# target to preprocess a source file
src/operators/OperatorImpl.cpp.i:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/OperatorImpl.cpp.i
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/OperatorImpl.cpp.i
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/OperatorImpl.cpp.i
.PHONY : src/operators/OperatorImpl.cpp.i

src/operators/OperatorImpl.s: src/operators/OperatorImpl.cpp.s
.PHONY : src/operators/OperatorImpl.s

# target to generate assembly for a file
src/operators/OperatorImpl.cpp.s:
	$(MAKE) -f CMakeFiles/Accessop.dir/build.make CMakeFiles/Accessop.dir/src/operators/OperatorImpl.cpp.s
	$(MAKE) -f CMakeFiles/Mapper.dir/build.make CMakeFiles/Mapper.dir/src/operators/OperatorImpl.cpp.s
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/OperatorImpl.cpp.s
.PHONY : src/operators/OperatorImpl.cpp.s

src/operators/Workerop.o: src/operators/Workerop.cpp.o
.PHONY : src/operators/Workerop.o

# target to build an object file
src/operators/Workerop.cpp.o:
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/Workerop.cpp.o
.PHONY : src/operators/Workerop.cpp.o

src/operators/Workerop.i: src/operators/Workerop.cpp.i
.PHONY : src/operators/Workerop.i

# target to preprocess a source file
src/operators/Workerop.cpp.i:
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/Workerop.cpp.i
.PHONY : src/operators/Workerop.cpp.i

src/operators/Workerop.s: src/operators/Workerop.cpp.s
.PHONY : src/operators/Workerop.s

# target to generate assembly for a file
src/operators/Workerop.cpp.s:
	$(MAKE) -f CMakeFiles/Workerop.dir/build.make CMakeFiles/Workerop.dir/src/operators/Workerop.cpp.s
.PHONY : src/operators/Workerop.cpp.s

src/proto/SMByteArrayHeader.pb.o: src/proto/SMByteArrayHeader.pb.cc.o
.PHONY : src/proto/SMByteArrayHeader.pb.o

# target to build an object file
src/proto/SMByteArrayHeader.pb.cc.o:
	$(MAKE) -f CMakeFiles/SMByteArrayHeader.dir/build.make CMakeFiles/SMByteArrayHeader.dir/src/proto/SMByteArrayHeader.pb.cc.o
.PHONY : src/proto/SMByteArrayHeader.pb.cc.o

src/proto/SMByteArrayHeader.pb.i: src/proto/SMByteArrayHeader.pb.cc.i
.PHONY : src/proto/SMByteArrayHeader.pb.i

# target to preprocess a source file
src/proto/SMByteArrayHeader.pb.cc.i:
	$(MAKE) -f CMakeFiles/SMByteArrayHeader.dir/build.make CMakeFiles/SMByteArrayHeader.dir/src/proto/SMByteArrayHeader.pb.cc.i
.PHONY : src/proto/SMByteArrayHeader.pb.cc.i

src/proto/SMByteArrayHeader.pb.s: src/proto/SMByteArrayHeader.pb.cc.s
.PHONY : src/proto/SMByteArrayHeader.pb.s

# target to generate assembly for a file
src/proto/SMByteArrayHeader.pb.cc.s:
	$(MAKE) -f CMakeFiles/SMByteArrayHeader.dir/build.make CMakeFiles/SMByteArrayHeader.dir/src/proto/SMByteArrayHeader.pb.cc.s
.PHONY : src/proto/SMByteArrayHeader.pb.cc.s

src/proto/SMOperatorInitParam.pb.o: src/proto/SMOperatorInitParam.pb.cc.o
.PHONY : src/proto/SMOperatorInitParam.pb.o

# target to build an object file
src/proto/SMOperatorInitParam.pb.cc.o:
	$(MAKE) -f CMakeFiles/SMOperatorInitParam.dir/build.make CMakeFiles/SMOperatorInitParam.dir/src/proto/SMOperatorInitParam.pb.cc.o
.PHONY : src/proto/SMOperatorInitParam.pb.cc.o

src/proto/SMOperatorInitParam.pb.i: src/proto/SMOperatorInitParam.pb.cc.i
.PHONY : src/proto/SMOperatorInitParam.pb.i

# target to preprocess a source file
src/proto/SMOperatorInitParam.pb.cc.i:
	$(MAKE) -f CMakeFiles/SMOperatorInitParam.dir/build.make CMakeFiles/SMOperatorInitParam.dir/src/proto/SMOperatorInitParam.pb.cc.i
.PHONY : src/proto/SMOperatorInitParam.pb.cc.i

src/proto/SMOperatorInitParam.pb.s: src/proto/SMOperatorInitParam.pb.cc.s
.PHONY : src/proto/SMOperatorInitParam.pb.s

# target to generate assembly for a file
src/proto/SMOperatorInitParam.pb.cc.s:
	$(MAKE) -f CMakeFiles/SMOperatorInitParam.dir/build.make CMakeFiles/SMOperatorInitParam.dir/src/proto/SMOperatorInitParam.pb.cc.s
.PHONY : src/proto/SMOperatorInitParam.pb.cc.s

src/socket/ClientSocket.o: src/socket/ClientSocket.cpp.o
.PHONY : src/socket/ClientSocket.o

# target to build an object file
src/socket/ClientSocket.cpp.o:
	$(MAKE) -f CMakeFiles/ClientSocket.dir/build.make CMakeFiles/ClientSocket.dir/src/socket/ClientSocket.cpp.o
.PHONY : src/socket/ClientSocket.cpp.o

src/socket/ClientSocket.i: src/socket/ClientSocket.cpp.i
.PHONY : src/socket/ClientSocket.i

# target to preprocess a source file
src/socket/ClientSocket.cpp.i:
	$(MAKE) -f CMakeFiles/ClientSocket.dir/build.make CMakeFiles/ClientSocket.dir/src/socket/ClientSocket.cpp.i
.PHONY : src/socket/ClientSocket.cpp.i

src/socket/ClientSocket.s: src/socket/ClientSocket.cpp.s
.PHONY : src/socket/ClientSocket.s

# target to generate assembly for a file
src/socket/ClientSocket.cpp.s:
	$(MAKE) -f CMakeFiles/ClientSocket.dir/build.make CMakeFiles/ClientSocket.dir/src/socket/ClientSocket.cpp.s
.PHONY : src/socket/ClientSocket.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... Accessop"
	@echo "... ClientSocket"
	@echo "... EndOfStreamHandler"
	@echo "... Mapper"
	@echo "... MongoDbDataSourceAdapter"
	@echo "... MyGridFS"
	@echo "... Operations"
	@echo "... RealTimeDataSourceAdapter"
	@echo "... SMByteArrayHeader"
	@echo "... SMOperatorInitParam"
	@echo "... SamplePartitioner"
	@echo "... Workerop"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Events"
	@echo "... GenerateEvents"
	@echo "... src/DataSourceAdapter/MongoDbDataSourceAdapter.o"
	@echo "... src/DataSourceAdapter/MongoDbDataSourceAdapter.i"
	@echo "... src/DataSourceAdapter/MongoDbDataSourceAdapter.s"
	@echo "... src/DataSourceAdapter/RealTimeDataSourceAdapter.o"
	@echo "... src/DataSourceAdapter/RealTimeDataSourceAdapter.i"
	@echo "... src/DataSourceAdapter/RealTimeDataSourceAdapter.s"
	@echo "... src/SamplePartitioner.o"
	@echo "... src/SamplePartitioner.i"
	@echo "... src/SamplePartitioner.s"
	@echo "... src/gridfs/MyGridFS.o"
	@echo "... src/gridfs/MyGridFS.i"
	@echo "... src/gridfs/MyGridFS.s"
	@echo "... src/operations/EndOfStreamHandler.o"
	@echo "... src/operations/EndOfStreamHandler.i"
	@echo "... src/operations/EndOfStreamHandler.s"
	@echo "... src/operations/operations.o"
	@echo "... src/operations/operations.i"
	@echo "... src/operations/operations.s"
	@echo "... src/operators/Accessop.o"
	@echo "... src/operators/Accessop.i"
	@echo "... src/operators/Accessop.s"
	@echo "... src/operators/Mapper.o"
	@echo "... src/operators/Mapper.i"
	@echo "... src/operators/Mapper.s"
	@echo "... src/operators/OperatorImpl.o"
	@echo "... src/operators/OperatorImpl.i"
	@echo "... src/operators/OperatorImpl.s"
	@echo "... src/operators/Workerop.o"
	@echo "... src/operators/Workerop.i"
	@echo "... src/operators/Workerop.s"
	@echo "... src/proto/SMByteArrayHeader.pb.o"
	@echo "... src/proto/SMByteArrayHeader.pb.i"
	@echo "... src/proto/SMByteArrayHeader.pb.s"
	@echo "... src/proto/SMOperatorInitParam.pb.o"
	@echo "... src/proto/SMOperatorInitParam.pb.i"
	@echo "... src/proto/SMOperatorInitParam.pb.s"
	@echo "... src/socket/ClientSocket.o"
	@echo "... src/socket/ClientSocket.i"
	@echo "... src/socket/ClientSocket.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
