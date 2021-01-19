cmake_minimum_required(VERSION 3.17)
project(gnl C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl cmake-build-debug/get_next_line.c cmake-build-debug/get_next_line.h cmake-build-debug/get_next_line_utils.c cmake-build-debug/main.c)