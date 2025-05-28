cmake_minimum_required(VERSION 3.20)
project(momservice)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(absl REQUIRED CONFIG) 



find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin REQUIRED)


add_library(protolib STATIC 
    ${CMAKE_CURRENT_BINARY_DIR}/../mom.pb.cc
    ${CMAKE_CURRENT_BINARY_DIR}/../mom.grpc.pb.cc
)

target_include_directories(protolib PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR} 
    ${Protobuf_INCLUDE_DIRS}
    ${grpc_INCLUDE_DIRS} 
)


set(SERVER_SRCS
    src/server.cc
    src/queue_obj.cc
    src/queue_list.cc
)

add_executable(server ${SERVER_SRCS})


target_link_libraries(server
    PRIVATE 
    protolib 
    ${Protobuf_LIBRARIES} 
    gRPC::grpc++       
    gRPC::grpc          
    absl::strings         
    absl::synchronization 
    utf8_validity
    Threads::Threads     
    dl                 
)

target_include_directories(server PRIVATE
    ${Protobuf_INCLUDE_DIRS}
    ${grpc_INCLUDE_DIRS}
)

