cmake_minimum_required(VERSION 3.7.2)
project(new_asm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ./asm_project/asm_source/asm.h ./asm_project/asm_source/asm_to_binary.c ./asm_project/asm_source/corewar.h ./asm_project/asm_source/corewar_valid.h ./asm_project/asm_source/ft_add_command_corewar.c ./asm_project/asm_source/ft_command.c ./asm_project/asm_source/ft_method.c ./asm_project/asm_source/ft_name_comment.c ./asm_project/asm_source/ft_strsplit_v2.c ./asm_project/asm_source/ft_valid_all.c ./asm_project/asm_source/ft_valid_command.c ./asm_project/asm_source/get_size_1.c ./asm_project/asm_source/get_size_2.c ./asm_project/asm_source/get_sizes.c ./asm_project/asm_source/hash.c ./asm_project/asm_source/main.c ./asm_project/asm_source/op.c ./asm_project/asm_source/op.h ./asm_project/asm_source/reg_dir_ind.c ./asm_project/asm_source/usage.c ./asm_project/asm_source/ft_strsplit_v3.c)
add_executable(new_asm ${SOURCE_FILES})
target_link_libraries(new_asm ${CMAKE_SOURCE_DIR}/libft/libft.a)