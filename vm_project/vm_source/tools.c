/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:11:07 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 15:11:17 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

int		get_arg(char bin_code, t_fork *fork, int arg, unsigned char *arena)
{
	if (bin_code == REG_CODE)
		return (fork->reg[arg - 1]);
	if (bin_code == IND_CODE)
		return (read_vm(arena, fork->pc + (arg % IDX_MOD)));
	return (arg);
}

int		get_arg_ni(char bin_code, t_fork *fork, int arg, unsigned char *arena)
{
	if (bin_code == REG_CODE)
		return (fork->reg[arg - 1]);
	if (bin_code == IND_CODE)
		return (read_vm(arena, fork->pc + arg));
	return (arg);
}

int		read_vm(unsigned char *arena, int index)
{
	int res;
	int temp;

	res = 0;
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

void	write_vm(t_machine *vm, t_fork *fork, int index, int var)
{
	unsigned i;

	i = 0;
	vm->arena[move_pc(index + 0)] = (var & 0xff000000) >> 24;
	vm->arena[move_pc(index + 1)] = (var & 0xff0000) >> 16;
	vm->arena[move_pc(index + 2)] = (var & 0xff00) >> 8;
	vm->arena[move_pc(index + 3)] = var & 0xff;
	if (vm->flags.flag == 'g')
	{
		while (i < vm->count_players && fork->id != vm->players[i].id)
			i++;
		if (i == vm->count_players)
			return ;
		vm->color_arena[move_pc(index + 0)] = green + i;
		vm->color_arena[move_pc(index + 1)] = green + i;
		vm->color_arena[move_pc(index + 2)] = green + i;
		vm->color_arena[move_pc(index + 3)] = green + i;
	}
}
