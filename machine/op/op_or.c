

#include "../machine.h"


void    op_or(int args[MAX_ARGS_NUMBER], t_machine *vm, t_forks *forks)
{
    int f_arg;
    int s_arg;

    f_arg = get_arg((args[3] >> 6) & 3, forks, args[0], vm->arena);
    s_arg = get_arg((args[3] >> 4) & 3, forks, args[1], vm->arena);
    forks->node.reg[args[2] - 1] = f_arg | s_arg;
}