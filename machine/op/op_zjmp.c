

#include "../machine.h"


void    op_zjmp(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    (void)vm;
    if (fork->carry == 1)
        fork->pc = move_pc(fork->pc + (args[0] % IDX_MOD));
    else
        fork->pc = move_pc(fork->pc + 3);
}