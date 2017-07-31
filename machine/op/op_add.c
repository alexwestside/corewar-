

#include "../machine.h"


void    op_add(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    (void)vm;
    fork->reg[args[2] - 1] = fork->reg[args[0] - 1] + fork->reg[args[1] - 1];
}