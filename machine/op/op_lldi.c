

#include "../machine.h"


void    op_lldi(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    int f_arg;
    int s_arg;

    f_arg = get_arg_noidx((args[3] >> 6) & 3, forks, args[0], vm->arena);
    s_arg = get_arg_noidx((args[3] >> 4) & 3, forks, args[1], vm->arena);
    forks->node.reg[args[2] - 1] = read_4_bytes(vm->arena, forks->node.pc + f_arg + s_arg);
}