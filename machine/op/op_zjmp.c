

#include "../machine.h"


void    op_zjmp(int args[MAX_ARGS_NUMBER], t_machine *vm, t_forks *fork)
{
    (void)vm;
    if (fork->node.carry == 1)
        fork->node.pc = move_pc(fork->node.pc + (args[0] % IDX_MOD));
    else
        fork->node.pc = move_pc(fork->node.pc + 3);
}