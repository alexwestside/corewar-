/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:06:07 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 23:06:11 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"


int 	check_corect_data_read(t_machine *vm, int index_player)
{
	if (vm->players[index_player].magic != COREWAR_EXEC_MAGIC)
		error_exit("Unvalid magic into player champions", 0, vm);
	if (vm->players[index_player].prog_size > CHAMP_MAX_SIZE)
		error_exit("Is too big to be a champion", 0, vm);
	return (0);
}


int		check_placement_players(t_machine vm)
{
	int i;
	int size;

	i = -1;
	size =  MEM_SIZE / vm.count_players;
	while (++i < vm.count_players)
		if (vm.players[i].prog_size > size)
			return (-2);
	return (0);
}