/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:54:42 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:54:44 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_lld(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	int f_reg;

	if (((args[3] >> 6) & 3) == DIR_CODE)
		f_reg = args[0];
	else
	{
		f_reg = read_vm(vm->arena, fork->pc + args[0]);
		f_reg &= 0xffff;
	}
	fork->reg[args[1] - 1] = f_reg;
}
