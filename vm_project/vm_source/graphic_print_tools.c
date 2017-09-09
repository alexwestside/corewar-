/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_print_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivanov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:34:56 by mivanov           #+#    #+#             */
/*   Updated: 2017/08/19 19:35:07 by mivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

static void	print_byte_code(t_machine vm, unsigned iter, int mod)
{
	int x;
	int y;
	int color;

	x = 3;
	y = 2;
	y = iter / 64 + y;
	x = (iter % 64) * 3 + x;
	color = vm.color_arena[iter];
	if (mod == 1)
		color += pc_green - 1;
	if (vm.color_arena[iter] == un_byte)
		attron(A_BOLD);
	attron(COLOR_PAIR(color));
	mvprintw(y, x, "%0.2hhx", vm.arena[iter]);
	attroff(COLOR_PAIR(color));
	if (vm.color_arena[iter] == un_byte)
		attroff(A_BOLD);
}

void		print_graph_arena(t_machine vm)
{
	unsigned i;

	i = 0;
	while (i < MEM_SIZE)
	{
		print_byte_code(vm, i, 0);
		i++;
	}
}

void		print_pc_arena(t_machine vm)
{
	t_fork *iter;

	iter = vm.head_lst;
	while (iter)
	{
		print_byte_code(vm, iter->pc, 1);
		iter = iter->next;
	}
}
