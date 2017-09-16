cmake_minimum_required(VERSION 3.7.2)
project(new_dasm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dasm.h op.c op.h)
add_executable(new_dasm ${SOURCE_FILES})
target_link_libraries(new_dasm ${CMAKE_SOURCE_DIR}/libft/libft.a)