/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:14:56 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 17:14:59 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_live(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	unsigned i;

	i = -1;
	fork->life = 1;
	vm->count_live++;
	while (++i < vm->count_players)
		if (vm->players[i].id == args[0])
		{
			print_flag(*vm, &vm->players[i], 1);
			vm->won_player = i;
			vm->players[i].count_live++;
			vm->players[i].last_live = (unsigned)vm->cycle;
			return ;
		}
}
