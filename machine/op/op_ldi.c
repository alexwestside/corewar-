

#include "../machine.h"

void    op_ldi(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    int f_reg;
    int s_reg;

    f_reg = get_arg((args[3] >> 6) & 3, forks, args[0], vm->arena) % IDX_MOD;
    s_reg = get_arg((args[3] >> 4) & 3, forks, args[1], vm->arena) % IDX_MOD;
    forks->node.reg[args[2] - 1] = read_4_bytes(vm->arena, forks->node.pc + (f_reg + s_reg) % IDX_MOD);
}