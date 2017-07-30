

#include "../machine.h"


void    op_lld(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    int f_reg;

    if (((args[3] >> 6) & 3) == DIR_CODE)
        f_reg = args[0];
    else
    {
        f_reg = read_4_bytes(vm->arena, forks->node.pc + args[0]);
        f_reg &= 0xffff;
    }
    forks->node.reg[args[1] - 1] = f_reg;
}