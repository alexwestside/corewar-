

#include "machine.h"


void    op_sti(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    int f_arg;
    int s_arg;
    int t_arg;

    f_arg = fork->reg[args[0] - 1];
    s_arg = get_arg((args[3] >> 4) & 3, fork, args[1], vm->arena);
    t_arg = get_arg((args[3] >> 2) & 3, fork, args[2], vm->arena);
    write_4_bytes(vm, fork, fork->pc + (s_arg + t_arg) % IDX_MOD, f_arg);
}
