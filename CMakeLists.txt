cmake_minimum_required(VERSION 3.7)
project(corewar2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES asm_to_binary.c sub.c ft_strsplit_v2.c ft_command.c ft_name_comment.c ft_valid_command.c get_sizes.c hash.c main.c op.c usage.c asm.h corewar.h corewar_valid.h reg_dir_ind.c)

add_executable(corewar2 ${SOURCE_FILES})

target_link_libraries(corewar2 ${CMAKE_SOURCE_DIR}/libft/libft.a)