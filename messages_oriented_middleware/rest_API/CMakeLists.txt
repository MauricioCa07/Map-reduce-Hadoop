cmake_minimum_required(VERSION 3.10)
project(mom)


add_executable(mom mom.cpp)

find_package(Crow REQUIRED)
target_link_libraries(mom PUBLIC Crow::Crow)

