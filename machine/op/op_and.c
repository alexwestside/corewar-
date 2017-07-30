

#include "../machine.h"


void    op_and(int args[MAX_ARGS_NUMBER], t_machine *vm, t_forks *forks)
{
    int f_reg;
    int s_reg;

    f_reg = get_arg((char) ((args[3] >> 6) & 3), forks, args[0], vm->arena);
    s_reg = get_arg((char) ((args[3] >> 4) & 3), forks, args[1], vm->arena);
    forks->node.reg[args[2] - 1] = f_reg & s_reg;
}