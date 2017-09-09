/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:50:42 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:50:45 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_ld(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	int tmp;

	if (((args[3] >> 6) & 3) == DIR_CODE)
		tmp = args[0];
	else
		tmp = read_vm(vm->arena, fork->pc + (args[0] % IDX_MOD));
	fork->reg[args[1] - 1] = tmp;
}
