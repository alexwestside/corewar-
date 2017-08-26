/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:47:14 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 21:47:17 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	release_memory(t_machine *vm)
{
	unsigned i;

	i = -1;
	if (vm == NULL)
		return ;
	free(vm->arena);
	vm->arena = NULL;
	free(vm->color_arena);
	vm->color_arena = NULL;
	all_delete(&vm->head_lst);
	vm->head_lst = NULL;
	while (++i < vm->count_players)
	{
		free(vm->players[i].code);
		vm->players[i].code = NULL;
	}
	free(vm->players);
	vm->players = NULL;
}
