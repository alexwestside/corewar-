
#include "machine.h"


int     move_pc(int pc)
{
    int move;

    move = pc % MEM_SIZE;
    return (move >= 0 ? move : -move);
}

//int     convert_t_label(int cmd, int label)
//{
//    int tmp_label;
//
//    if (label == REG_CODE)
//        tmp_label = T_REG;
//    else if (label == DIR_CODE)
//        tmp_label = T_DIR;
//    else if (label == IND_CODE)
//        tmp_label = T_IND;
//    else
//        tmp_label = 0; // error
//    return (tmp_label);
//}

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

static  int     check_valid_params(int cmd, size_t *size, int code_octal, int i)
{
    int     tmp;
    int     code;

    tmp = i == 0 ? 6 : 6 - (2 * i);
    tmp = code_octal >> tmp & 3;
    code = convert_code_into_t_code(tmp);
    if (g_op_tab[cmd].param_types[i] & code)
    {
        tmp == REG_CODE ? size = (size_t *)REG_SIZE : 0;
        if (DIR_CODE && size == 0)
            size = (size_t *)(GET_DIR_SIZE(cmd));
        tmp == IND_CODE && size == 0 ? size = (size_t *)IND_SIZE : 0;
    }
    return (size ? 1 : 0);
}

static  int  move_pc_into_args(int index, int pc, int code_octal, int cmd)
{
    int tmp;

    if (index == 0)
        return (move_pc(pc + 1));
    tmp = 6 - 2 * index;
    tmp = code_octal >> tmp & 3;
    if (tmp == REG_CODE)
        return (move_pc(pc + REG_SIZE));
    if (tmp == DIR_CODE)
        return (move_pc(pc + GET_DIR_SIZE(cmd)));
    if (tmp == IND_CODE)
        return (move_pc(pc + IND_SIZE));
    return (pc);
}


int     read_int(t_machine *vm, int pc, size_t size)
{
    int           i;
    unsigned char num[REG_SIZE]; // max size for all params

    i = 0;
    if (size == 0)
        return (0);
    ft_bzero(num, REG_SIZE);
    while (size)
    {
        num[i++] = vm->arena[move_pc(pc + (int)size)];
        size--;
    }
    return (*(int *)num);
}


void    shift_pc_on_map(t_forks *fork, int pc, int  cmd)
{
    if (cmd != 8)
    {
        if (g_op_tab[cmd].cod_oct == 1)
            fork->node.pc = move_pc(pc);
        else
            fork->node.pc = move_pc(pc + GET_DIR_SIZE(cmd));
    }
}



// при виклику даної функції треба перевірити чи cmd належить діапазону командів, якщо
// ні то змістити даний процесор на одну позицію
void    handling_args(int cmd, t_machine *vm, t_forks **tmp)
{
    size_t       size;
    int          args[MAX_ARGS_NUMBER];
    int          pc;
    short        i;
    int          f;

    i = -1;
    f = 1;
    pc = move_pc((*tmp)->node.pc + 1);
    ft_bzero(args, sizeof(args) * MAX_ARGS_NUMBER);
    args[3] = g_op_tab[cmd].cod_oct == 1 ? (int)vm->arena[pc] : 0;
    if (g_op_tab[cmd].cod_oct == 0)
        args[0] = read_int(vm, pc, GET_DIR_SIZE(cmd));
    else
        while (++i < g_op_tab[cmd].params)
        {
            size = 0;
            f = f && check_valid_params(cmd, &size, args[3], i) ? 1 : 0;
            pc = move_pc_into_args(i, pc, args[3], cmd);
            args[i] = size > 0 && f == 1 ? read_int(vm, pc, size) : 0;
        }
    if (g_op_tab[cmd].cod_oct == 0 || i == g_op_tab[cmd].params)
        run_op_cmd(cmd, args, *tmp, vm);
    shift_pc_on_map(*tmp, pc, cmd);
}

