cmake_minimum_required(VERSION 3.19)
project(string_and_char C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS  "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
add_executable(string_and_char main.c)