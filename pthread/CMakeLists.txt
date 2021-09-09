cmake_minimum_required(VERSION 3.20)
project(pthread)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(pthread main.cpp)
