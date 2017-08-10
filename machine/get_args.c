
#include "machine.h"

unsigned     move_pc(int pc)
{
    int move;
    unsigned res;

    move = pc % MEM_SIZE;
    if (move >= 0)
        res = (unsigned)move;
    else
        res = (unsigned)move * (-1);
    return (res);
//    return (move >= 0 ? move : -move);
}

int     convert_code_into_t_code(int label)
{
    if (label == T_REG)
        return (REG_CODE);
    if (label == T_DIR)
        return (DIR_CODE);
    if (label == T_IND)
        return (IND_CODE);
    return (0);
}

static  size_t      get_size_read(int cmd, int code_octal, int i, int *valid)
{
    int tmp;
    int code;
    size_t size;

    size = 0;
    tmp = i == 0 ? 6 : 6 - (2 * i);
    tmp = code_octal >> tmp & 3;
    code = convert_code_into_t_code(tmp);
    if (g_op_tab[cmd].param_types[i] & code)
    {
        if (tmp == REG_CODE)
            size = REG_SIZE;
        else if (tmp == DIR_CODE)
            size = (size_t)g_op_tab[cmd].size;
        else if (tmp == IND_CODE)
            size = IND_SIZE;
    }
    *valid += size ? 1 : 0;
    return (size);
}

static unsigned  move_pc_into_args(int index, unsigned pc, int code_octal, int cmd)
{
    int tmp;

//    if (index == 0)
//        return (move_pc(pc + 1));
    tmp = 6 - 2 * index;
    tmp = code_octal >> tmp & 3;
    if (tmp == REG_CODE)
        return (move_pc(pc + REG_SIZE));
    if (tmp == DIR_CODE)
        return (move_pc(pc + g_op_tab[cmd].size));
    if (tmp == IND_CODE)
        return (move_pc(pc + IND_SIZE));
    return (pc);
}

int     read_int(t_machine vm, unsigned pc, size_t size)
{
    int         i;
    int         f;
    unsigned char num[3]; // size type int

    i = 0;
    if (size == 0)
        return (0);
    ft_bzero(num, 4);
    f = vm.arena[move_pc(pc + 1)] > 127 ? 1 : 0;
    while (size)
        num[i++] = vm.arena[move_pc(pc + (int)size--)];
    while (f && i <= 3)
        num[i++] = 0xff;
    int n = *(int *)num;
    return (n);
}


void    shift_pc_on_map(t_fork *fork, int pc, int  cmd)
{
    if (cmd != 8)
    {
        if (g_op_tab[cmd].cod_oct == 1)
            fork->pc = move_pc(pc);
        else
            fork->pc = move_pc(pc + g_op_tab[cmd].size);
    }
}

void    handling_args(int cmd, t_machine *vm, t_fork *tmp)
{
    size_t     size;
    int          args[MAX_ARGS_NUMBER];
    unsigned     pc;
    short        i;
    int          f;

    i = -1;
    f = 0;
    ft_bzero(args, sizeof(*args) * MAX_ARGS_NUMBER);
    pc = g_op_tab[cmd].cod_oct == 1 ? move_pc(tmp->pc + 1) : tmp->pc;
    args[3] = g_op_tab[cmd].cod_oct == 1 ? (int)vm->arena[pc] : 0;
    if (g_op_tab[cmd].cod_oct == 0)
        args[0] = read_int(*vm, pc, (size_t)g_op_tab[cmd].size);
    else
        while (++i < g_op_tab[cmd].params)
        {
            size = get_size_read(cmd, args[3], i, &f);
            args[i] = size > 0 ? read_int(*vm, pc, size) : 0;
            pc = move_pc_into_args(i, pc, args[3], cmd);
        }
    if (g_op_tab[cmd].cod_oct == 0 || f == g_op_tab[cmd].params)
        run_op_cmd(cmd, args, tmp, vm);
    shift_pc_on_map(tmp, pc + 1, cmd);
}
