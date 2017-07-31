
#include "machine.h"


static void     change_carry(int cmd, t_fork *fork, int *args)
{
    int tmp;

    tmp = g_op_tab[cmd].params - 1;
    fork->carry = fork->reg[args[tmp] - 1] == 0 ? 1 : 0;
}

/*
** if argument is T_REG, but not valid, then skip command and args
*/

void    run_op_cmd(int cmd, int *args, t_fork *fork, t_machine *vm)
{
    if (((((args[3] >> 6) & 3) == REG_CODE) && !IS_VAL_REG(args[0]))
        || ((((args[3] >> 4) & 3) == REG_CODE) && !IS_VAL_REG(args[1]))
        || ((((args[3] >> 2) & 3) == REG_CODE) && !IS_VAL_REG(args[2])))
        return ;
    if (g_op_tab[cmd].carry == 1)
        change_carry(cmd, fork, args);
    g_opfunc[cmd].func(args, fork, vm);
}