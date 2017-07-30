

#include "../machine.h"


void    op_add(int args[MAX_ARGS_NUMBER], t_machine *vm, t_forks *forks)
{
    (void)vm;
    forks->node.reg[args[2] - 1] = forks->node.reg[args[0] - 1] +
            forks->node.reg[args[1] - 1];
}