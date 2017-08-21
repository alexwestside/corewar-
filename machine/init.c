/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:05:08 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 13:05:21 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

t_player	*create_players(int count)
{
	int			i;
	t_player	*players;

	i = -1;
	players = (t_player *)malloc(count * sizeof(t_player));
	while (players && ++i < count)
	{
		players[i].id = 0;
		players[i].last_live = 0;
		players[i].count_live = 0;
		players[i].magic = 0;
		ft_bzero(players[i].prog_name, PROG_NAME_LENGTH);
		players[i].prog_size = 0;
		ft_bzero(players[i].comment, PROG_NAME_LENGTH);
		players[i].code = NULL;
	}
	return (players ? players : NULL);
}

void		init_vm(t_machine *vm, char **argv)
{
	if (vm->count_players == 0)
		usage(2, argv[1], NULL);
	vm->head_lst = NULL;
	vm->cycle = 0;
	vm->count_live = 0;
	vm->iter_cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->iter_max_checks = 0;
	vm->players = create_players(vm->count_players);
	vm->arena = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->color_arena = (unsigned char *)malloc(MEM_SIZE * sizeof(unsigned char));
	if (vm->arena == NULL || vm->color_arena == NULL)
		error_exit("some thing wrong", 999, vm);
	ft_memset(vm->color_arena, un_byte, MEM_SIZE);
	vm->count_forks = 0;
	vm->won_player = 0;
}
