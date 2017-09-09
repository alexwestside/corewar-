/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:01:54 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 17:01:56 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_zjmp(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	(void)vm;
	if (fork->carry == 1)
		fork->pc = move_pc(fork->pc + (args[0] % IDX_MOD));
	else
		fork->pc = move_pc(fork->pc + 3);
}
