cmake_minimum_required(VERSION 3.10)
project(protobuf_temp)

set(CMAKE_CXX_STANDARD 14)
  
find_package(Protobuf CONFIG REQUIRED)
 
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
 
set(PROTO_SRCS "uart.pb.cc")
set(PROTO_HDRS "uart.pb.h")
 
add_executable(protobuf_temp main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
 
target_link_libraries(protobuf_temp PRIVATE protobuf::libprotobuf)
