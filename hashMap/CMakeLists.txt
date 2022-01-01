cmake_minimum_required(VERSION 3.20)
project(hashMap C)

set(CMAKE_C_STANDARD 99)

add_executable(hashMap main.c hashmap.h hashmap.c)
