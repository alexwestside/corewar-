

#include "../machine.h"


void    op_st(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    int f_arg;
    int s_arg;

    f_arg = fork->reg[args[0] - 1];
    if (((args[3] >> 4) & 3) == IND_CODE)
    {
        s_arg = args[1];
        write_4_bytes(vm, fork, fork->pc + (s_arg % IDX_MOD), f_arg);
    }
    else
        fork->reg[args[1] - 1] = f_arg;
}
