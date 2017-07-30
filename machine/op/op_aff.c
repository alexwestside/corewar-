

#include "../machine.h"


void    op_aff(int args[MAX_ARGS_NUMBER], t_forks *forks, t_machine *vm)
{
    (void)args;
    if (vm->visual_flag == 0)
        ft_printf("Aff: %c\n", forks->node.reg[args[0] - 1] % 256);
}