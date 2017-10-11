cmake_minimum_required(VERSION 3.7.2)
project(new_asm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ./asm_project/asm_source/asm.h ./asm_project/asm_source/asm_to_binary.c ./asm_project/asm_source/corewar.h ./asm_project/asm_source/corewar_valid.h ./asm_project/asm_source/ft_add_command_corewar.c ./asm_project/asm_source/ft_command.c ./asm_project/asm_source/ft_method.c ./asm_project/asm_source/ft_name_comment.c ./asm_project/asm_source/ft_strsplit_v2.c ./asm_project/asm_source/ft_valid_all.c ./asm_project/asm_source/ft_valid_command.c ./asm_project/asm_source/get_size_1.c ./asm_project/asm_source/get_size_2.c ./asm_project/asm_source/get_sizes.c ./asm_project/asm_source/hash.c ./asm_project/asm_source/main.c ./asm_project/asm_source/op.c ./asm_project/asm_source/op.h ./asm_project/asm_source/reg_dir_ind.c ./asm_project/asm_source/usage.c ./asm_project/asm_source/ft_strsplit_v3.c)



add_executable(new_asm ${SOURCE_FILES})
target_link_libraries(new_asm ${CMAKE_SOURCE_DIR}/libft/libft.a)


#cmake_minimum_required(VERSION 3.7.2)
#project(new_corewar)
#
#set(CMAKE_C_STANDARD 99)
#
#set(SOURCE_FILES
#        ./vm_project/vm_source/auxiliary_func.c
#        ./vm_project/vm_source/err_exit.c
#        ./vm_project/vm_source/func_fork.c
#        ./vm_project/vm_source/get_args.c
#        ./vm_project/vm_source/get_flags.c
#        ./vm_project/vm_source/get_path_files.c
#        ./vm_project/vm_source/graphic_key.c
#        ./vm_project/vm_source/graphic_mode.c
#        ./vm_project/vm_source/graphic_print_tools.c
#        ./vm_project/vm_source/graphic_static.c
#        ./vm_project/vm_source/init.c
#        ./vm_project/vm_source/init_number_players.c
#        ./vm_project/vm_source/machine.h
#        ./vm_project/vm_source/main.c
#        ./vm_project/vm_source/op_add.c
#        ./vm_project/vm_source/op_aff.c
#        ./vm_project/vm_source/op_and.c
#        ./vm_project/vm_source/op_fork.c
#        ./vm_project/vm_source/op_ld.c
#        ./vm_project/vm_source/op_ldi.c
#        ./vm_project/vm_source/op_lfork.c
#        ./vm_project/vm_source/op_live.c
#        ./vm_project/vm_source/op_lld.c
#        ./vm_project/vm_source/op_lldi.c
#        ./vm_project/vm_source/op_or.c
#        ./vm_project/vm_source/op_st.c
#        ./vm_project/vm_source/op_sti.c
#        ./vm_project/vm_source/op_sub.c
#        ./vm_project/vm_source/op_xor.c
#        ./vm_project/vm_source/op_zjmp.c
#        ./vm_project/vm_source/print.c
#        ./vm_project/vm_source/read_file.c
#        ./vm_project/vm_source/release_memory.c
#        ./vm_project/vm_source/run_op_cmd.c
#        ./vm_project/vm_source/tools.c
#        ./vm_project/vm_source/tools2.c
#        ./vm_project/vm_source/validate_data.c
#        ./vm_project/vm_source/work_vm.c
#        )
#
#add_executable(new_corewar ${SOURCE_FILES})
#set(CURSES_NEED_NCURSES TRUE)
#find_package(Curses REQUIRED)
#if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
#    include_directories(${CURSES_INCLUDE_DIR})
#    target_link_libraries (new_corewar ${CURSES_LIBRARIES})
#endif()
#target_link_libraries(new_corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)