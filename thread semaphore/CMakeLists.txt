cmake_minimum_required(VERSION 3.20)
project(thread_semaphore)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(thread_semaphore main.cpp)

