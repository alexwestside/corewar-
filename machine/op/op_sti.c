

#include "../machine.h"


void    op_sti(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    int f_arg;
    int s_arg;
    int t_arg;

    f_arg = forks->node.reg[args[0] - 1];
    s_arg = get_arg((args[3] >> 4) & 3, forks, args[1], vm->arena);
    t_arg = get_arg((args[3] >> 2) & 3, forks, args[2], vm->arena);
    write_4_bytes(vm, forks, forks->node.pc + (s_arg + t_arg) % IDX_MOD, f_arg);
}