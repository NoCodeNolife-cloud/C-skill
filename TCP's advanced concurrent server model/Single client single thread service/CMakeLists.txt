cmake_minimum_required(VERSION 3.20)
project(Single_client_single_thread_service)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Single_client_single_thread_service main.cpp)

