

#include "../machine.h"


void    op_lldi(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    int f_arg;
    int s_arg;

    f_arg = get_arg_noidx((args[3] >> 6) & 3, fork, args[0], vm->arena);
    s_arg = get_arg_noidx((args[3] >> 4) & 3, fork, args[1], vm->arena);
    fork->reg[args[2] - 1] = read_4_bytes(vm->arena, fork->pc + f_arg + s_arg);
}