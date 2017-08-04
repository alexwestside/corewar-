cmake_minimum_required(VERSION 3.7)

project(corewar)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        ./machine/machine.h
        op.h
        ./machine/op/op_add.c
        ./machine/op/tools.c
        ./machine/op/op_aff.c
        ./machine/op/op_and.c
        ./machine/op/op_ld.c
        ./machine/op/op_ldi.c
        ./machine/op/op_lld.c
        ./machine/op/op_lldi.c
        ./machine/op/op_or.c
        ./machine/op/op_st.c
        ./machine/op/op_sti.c
        ./machine/op/op_sub.c
        ./machine/op/op_xor.c
        ./machine/op/op_zjmp.c
        ./machine/create_vm.c
        ./machine/init_players.c
        ./machine/print.c
        ./machine/read_file.c
        ./machine/validate_data.c
        ./machine/get_args.c
        ./machine/run_op_cmd.c
        ./machine/func_fork.c
        ./machine/main.c
        ./machine/work_vm.c
        ./machine/init.c
        ./machine/op_func.c
        ./machine/usage.c
        op.c machine/op/op_fork.c machine/op/op_lfork.c machine/op/op_live.c machine/release_memory.c machine/init_number_players.c)
add_executable(corewar ${SOURCE_FILES})
target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)