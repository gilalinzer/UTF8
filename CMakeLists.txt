cmake_minimum_required(VERSION 3.27)
project(UTF8 C)

set(CMAKE_C_STANDARD 11)

add_executable(UTF8 main.c
        main.h
        test.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")