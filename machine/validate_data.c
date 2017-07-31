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


int 	check_corect_data_read(t_machine vm, int index_player)
{
	if (vm.players[index_player].magic != COREWAR_EXEC_MAGIC)
		return (-1);
	if (vm.size_code_players[index_player] != vm.players[index_player].prog_size)
		return (-1);
	if (vm.players[index_player].prog_size > CHAMP_MAX_SIZE)
		return (-1);
	return (0);
}


int		check_placement_players(t_machine vm)
{
	int i;
	int size;

	i = -1;
	size =  MEM_SIZE / vm.count_players;
	while (++i < vm.count_players)
		if (vm.size_code_players[i] > size)
			return (-2);
	return (0);
}