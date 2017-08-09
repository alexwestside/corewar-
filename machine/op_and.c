

#include "machine.h"


void    op_and(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    int f_reg;
    int s_reg;

    f_reg = get_arg((char) ((args[3] >> 6) & 3), fork, args[0], vm->arena);
    s_reg = get_arg((char) ((args[3] >> 4) & 3), fork, args[1], vm->arena);
    fork->reg[args[2] - 1] = f_reg & s_reg;
}
