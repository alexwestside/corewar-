cmake_minimum_required(VERSION 3.7)
project(corewar_orizhiy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c op.c)

add_executable(corewar_orizhiy ${SOURCE_FILES})