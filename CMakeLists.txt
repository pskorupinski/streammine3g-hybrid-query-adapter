cmake_minimum_required(VERSION 2.8)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build)

if(DEFINED STREAMMINE3G_ROOT)
    include_directories(${STREAMMINE3G_ROOT}/)
endif(DEFINED STREAMMINE3G_ROOT)

#find_package(JNI REQUIRED)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

#new code
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

find_path(LOG4CXX_INCLUDE_FILE logger.h PATHS /include/log4cxx /usr/include/log4cxx /usr/local/include/log4cxx)
find_library(LOG4CXX NAMES log4cxx log4cxxd PATHS /lib /usr/lib /usr/local/lib)

if(NOT LOG4CXX)
    message(FATAL_ERROR "log4cxx not found!")
else(LOG4CXX)
    message(STATUS "Found log4cxx: ${LOG4CXX}")
    SET(LOG4CXX_LIBRARIES log4cxx.a aprutil-1.a apr-1.a expat.a)
endif(NOT LOG4CXX)

if(DEFINED GPB_ROOT) 
    message("GPB_ROOT" ${GPB_ROOT})
    find_library(GPB protobuf "protobuf library" NO_DEFAULT_PATH PATHS ${GPB_ROOT}/lib/)
else()
    find_library(GPB protobuf "protobuf library")
endif()

if( NOT GPB)
    message(FATAL_ERROR "protobuf not found!")
else(GPB)
    message(STATUS "Found protobuf: ${GPB}")
endif(NOT GPB)

set(PROTOC_CMD "protoc")

if(DEFINED GPB_ROOT)
    include_directories(${GPB_ROOT}/include/)
    link_directories(${GPB_ROOT}/lib/)
    set(PROTOC_CMD "${GPB_ROOT}/bin/protoc")
    set(GPB_LIB "${GPB_ROOT}/lib/libprotobuf.a")
endif(DEFINED GPB_ROOT)
 
add_subdirectory(Events)

include_directories(${CMAKE_BINARY_DIR})

# proto
add_library(SMOperatorInitParam SHARED src/proto/SMOperatorInitParam.pb.cc)
add_library(SMByteArrayHeader SHARED src/proto/SMByteArrayHeader.pb.cc)

# socket
#add_library(Socket SHARED src/socket/Socket.cpp)
add_library(ClientSocket SHARED src/socket/ClientSocket.cpp)

# gridfs
add_library(MyGridFS SHARED src/gridfs/MyGridFS.cpp)

# operations
add_library(Operations SHARED src/operations/operations.cpp)
add_library(EndOfStreamHandler SHARED src/operations/EndOfStreamHandler.cpp)

# datasourceadapter
add_library(MongoDbDataSourceAdapter SHARED src/DataSourceAdapter/MongoDbDataSourceAdapter.cpp)
add_library(RealTimeDataSourceAdapter SHARED src/DataSourceAdapter/RealTimeDataSourceAdapter.cpp)

# operators
add_library(Accessop SHARED src/operators/Accessop.cpp src/operators/OperatorImpl.cpp)
add_library(Workerop SHARED src/operators/Workerop.cpp src/operators/OperatorImpl.cpp)
add_library(Mapper SHARED src/operators/Mapper.cpp src/operators/OperatorImpl.cpp)

# partitioner
add_library(SamplePartitioner SHARED src/SamplePartitioner.cpp)

# LINK LIBRARIES
target_link_libraries(MyGridFS boost_system-mt mongoclient boost_thread-mt boost_filesystem-mt boost_program_options-mt)
target_link_libraries(ClientSocket boost_system-mt pthread)
target_link_libraries(MongoDbDataSourceAdapter MyGridFS)
target_link_libraries(RealTimeDataSourceAdapter ClientSocket)
target_link_libraries(Accessop SMOperatorInitParam SMByteArrayHeader MongoDbDataSourceAdapter RealTimeDataSourceAdapter EndOfStreamHandler)
#target_link_libraries(Accessop SMOperatorInitParam SMByteArrayHeader RealTimeDataSourceAdapter EndOfStreamHandler)
target_link_libraries(Mapper SMByteArrayHeader EndOfStreamHandler)
target_link_libraries(Workerop SMByteArrayHeader EndOfStreamHandler)
target_link_libraries(SamplePartitioner Operations)
