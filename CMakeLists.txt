cmake_minimum_required(VERSION 3.7)

project(corewar)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        ./machine/machine.h
        op.h
#        graphical_mode.c
        machine/op_add.c
        machine/tools.c
        machine/op_aff.c
        machine/op_and.c
        machine/op_ld.c
        machine/op_ldi.c
        machine/op_lld.c
        machine/op_lldi.c
        machine/op_or.c
        machine/op_st.c
        machine/op_sti.c
        machine/op_sub.c
        machine/op_xor.c
        machine/op_zjmp.c
        ./machine/print.c
        ./machine/read_file.c
        ./machine/validate_data.c
        ./machine/get_args.c
        ./machine/run_op_cmd.c
        ./machine/func_fork.c
        ./machine/main.c
        ./machine/work_vm.c
        ./machine/init.c
        ./machine/usage.c
        op.c machine/op_fork.c machine/op_lfork.c machine/op_live.c machine/release_memory.c machine/init_number_players.c)
add_executable(corewar ${SOURCE_FILES})
target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)