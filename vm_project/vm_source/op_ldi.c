/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:52:55 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 17:16:05 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_ldi(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	int f_reg;
	int s_reg;

	f_reg = get_arg((args[3] >> 6) & 3, fork, args[0], vm->arena) % IDX_MOD;
	s_reg = get_arg((args[3] >> 4) & 3, fork, args[1], vm->arena) % IDX_MOD;
	fork->reg[args[2] - 1] = read_vm(vm->arena,
	fork->pc + (f_reg + s_reg) % IDX_MOD);
}
