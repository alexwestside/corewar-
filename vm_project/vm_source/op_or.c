/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:56:59 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:57:01 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_or(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	int f_arg;
	int s_arg;

	f_arg = get_arg((args[3] >> 6) & 3, fork, args[0], vm->arena);
	s_arg = get_arg((args[3] >> 4) & 3, fork, args[1], vm->arena);
	fork->reg[args[2] - 1] = f_arg | s_arg;
}
