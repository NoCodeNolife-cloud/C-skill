cmake_minimum_required(VERSION 3.20)
project(SYN_flood_attack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(SYN_flood_attack main.cpp)

