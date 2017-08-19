cmake_minimum_required(VERSION 3.6)
project(machine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    create_vm.c
    machine.h
    main.c
    validate_data.c)

add_executable(machine ${SOURCE_FILES})