cmake_minimum_required(VERSION 3.20)
project(thread_mutex)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(thread_mutex main.cpp)
