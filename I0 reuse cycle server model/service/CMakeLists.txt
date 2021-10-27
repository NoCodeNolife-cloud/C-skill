cmake_minimum_required(VERSION 3.20)
project(service)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(service main.cpp)

