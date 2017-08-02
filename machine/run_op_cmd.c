
#include "machine.h"


static void     change_carry(int cmd, t_fork *fork, int *args)
{
    int tmp;

    tmp = g_op_tab[cmd].params - 1;
    fork->carry = fork->reg[args[tmp] - 1] == 0 ? 1 : 0;
}

void    switch_op_cmd(int cmd, int *args, t_fork *fork, t_machine *vm)
{
    static t_opfunc	opfunc[] =
            {
                    {0,   &op_live},
                    {1,   &op_ld},
                    {2,   &op_st},
                    {3,   &op_add},
                    {4,   &op_sub},
                    {5,   &op_and},
                    {6,   &op_or},
                    {7,   &op_xor},
                    {8,   &op_zjmp},
                    {9,   &op_ldi},
                    {10,  &op_sti},
                    {11,  &op_fork},
                    {12,  &op_lld},
                    {13,  &op_lldi},
                    {14,  &op_lfork},
                    {15,  &op_aff}
            };
    if (0 <= cmd < 17)
        opfunc[cmd].func(args, fork, vm);
}


/*
** if argument is T_REG, but not valid, then skip command and args
*/

void    run_op_cmd(int cmd, int *args, t_fork *fork, t_machine *vm)
{
    if (((((args[3] >> 6) & 3) == REG_CODE) && !(0 < args[0] < 17))
        || ((((args[3] >> 4) & 3) == REG_CODE) && !(0 < args[1] < 17))
        || ((((args[3] >> 2) & 3) == REG_CODE) && !(0 < args[2] < 17)))
        return ;
    switch_op_cmd(cmd, args, fork, vm);
    if (g_op_tab[cmd].carry == 1)
        change_carry(cmd, fork, args);
//    g_opfunc[cmd].func(args, fork, vm);
}