

#include "../machine.h"


void    op_ld(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    int tmp;

    if (((args[3] >> 6) & 3) == DIR_CODE)
        tmp = args[0];
    else
        tmp = read_4_bytes(vm->arena, forks->node.pc + (args[0] % IDX_MOD));
    forks->node.reg[args[1] - 1] = tmp;
}