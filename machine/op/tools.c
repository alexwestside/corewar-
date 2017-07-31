

#include "../machine.h"

int		read_4_bytes(unsigned char *arena, int index)
{
    int	res;
    int	temp;

    res = 0;
    temp = 0;
    temp = arena[move_pc(index + 0)];
    temp <<= 24;
    res |= temp;
    temp = arena[move_pc(index + 1)];
    temp <<= 16;
    res |= temp;
    temp = arena[move_pc(index + 2)];
    temp <<= 8;
    res |= temp;
    temp = arena[move_pc(index + 3)];
    res |= temp;
    return (res);
}

void	write_4_bytes(t_machine *vm, t_fork *fork, int index, int var)
{
    (void)fork;
    vm->arena[move_pc(index + 0)] = (var & 0xff000000) >> 24;
    vm->arena[move_pc(index + 1)] = (var & 0xff0000) >> 16;
    vm->arena[move_pc(index + 2)] = (var & 0xff00) >> 8;
    vm->arena[move_pc(index + 3)] = var & 0xff;
}



int		get_arg(char bin_code, t_fork *fork, int arg, unsigned char *arena)
{
    if (bin_code == REG_CODE)
        return (fork->reg[arg - 1]);
    if (bin_code == IND_CODE)
        return (read_4_bytes(arena, fork->pc + (arg % IDX_MOD)));
    return (arg);
}

int		get_arg_noidx(char bin_code, t_fork *fork, int arg, unsigned char *arena)
{
    if (bin_code == REG_CODE)
        return (fork->reg[arg - 1]);
    if (bin_code == IND_CODE)
        return (read_4_bytes(arena, fork->pc + arg));
    return (arg);
}