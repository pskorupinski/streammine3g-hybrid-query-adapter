macro(EventCompileTask EventFile)

add_custom_command(
	COMMAND ${PROTOC_CMD}
	ARGS	--proto_path=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${EventFile}.proto
	OUTPUT ${CMAKE_BINARY_DIR}/${EventFile}.pb.cc ${CMAKE_BINARY_DIR}/${EventFile}.pb.h
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${EventFile}.proto
	COMMENT "Running Google Protocol Buffers Compiler for ${EventFile}..."
)
endmacro(EventCompileTask)

#
#  Google Protocol Buffers Patch for preventing segfault when tearing down the system 
#  as the code for releasing buffers of operators/managers does not exist anymore during shutdown of StreamMine3G 
#

macro(EventCompileTaskPatch1 EventFile)

add_custom_command(
    COMMAND sed
    ARGS 's/::google::protobuf::internal::OnShutdown/GPBPatch::InitShutdownFunctions\(\)\;GPBPatch::OnShutdown/' ${CMAKE_BINARY_DIR}/${EventFile}.pb.cc > ${CMAKE_BINARY_DIR}/${EventFile}.pb.c1
    OUTPUT ${CMAKE_BINARY_DIR}/${EventFile}.pb.c1
    DEPENDS ${CMAKE_BINARY_DIR}/${EventFile}.pb.cc
    COMMENT "Running Google Protocol Buffers Compiler (patch1) for ${EventFile}..."
)

endmacro(EventCompileTaskPatch1)

macro(EventCompileTaskPatch2 EventFile)

add_custom_command(
    COMMAND sed
    ARGS "1i#include \\\"../src/GPBPatch.hpp\\\"" ${CMAKE_BINARY_DIR}/${EventFile}.pb.c1 > ${CMAKE_BINARY_DIR}/${EventFile}.pb.cpp
    OUTPUT ${CMAKE_BINARY_DIR}/${EventFile}.pb.cpp
    DEPENDS ${CMAKE_BINARY_DIR}/${EventFile}.pb.c1
    COMMENT "Running Google Protocol Buffers Compiler (patch2) for ${EventFile}..."
)

endmacro(EventCompileTaskPatch2)

file(GLOB_RECURSE eventFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" eventFilesIn "${eventFiles}")
string(REPLACE ".proto" "" eventFilesIn "${eventFilesIn}")

string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_BINARY_DIR}/" eventFilesOut "${eventFiles}")
string(REPLACE ".proto" ".pb.cpp" eventFilesOut "${eventFilesOut}")

foreach(var eventFilesIn)
    foreach(item ${${var}})
        EventCompileTask(${item})
        EventCompileTaskPatch1(${item})
        EventCompileTaskPatch2(${item})
    endforeach(item)
endforeach(var)

add_custom_target(GenerateEvents DEPENDS ${eventFilesOut})
add_library(Events STATIC ${eventFilesOut})
