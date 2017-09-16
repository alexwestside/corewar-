/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivanov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:37:53 by mivanov           #+#    #+#             */
/*   Updated: 2017/08/19 19:38:15 by mivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

static void	draw_border(void)
{
	char	sing;
	int		height;
	int		width;

	sing = '*';
	height = 68;
	width = 254;
	attron(COLOR_PAIR(100));
	vline(sing, height - 1);
	hline(sing, width);
	move(height - 1, 0);
	hline(sing, width);
	move(0, width);
	vline(sing, height);
	move(0, 197);
	vline(sing, height);
	attroff(COLOR_PAIR(100));
}

static void	static_submenu_top(t_machine vm, t_graf graf, unsigned cycle)
{
	int y;
	int x;

	y = 3;
	x = 197 + 3;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	mvprintw(y + 2, x, "Cycles/second limit : %.0f", graf.speed);
	mvprintw(y + 5, x, "Cycle : %u", cycle);
	mvprintw(y + 7, x, "Processes : %u", vm.count_forks);
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

static void	print_static_players(t_machine vm)
{
	int			y;
	int			x;
	unsigned	i;

	i = -1;
	y = 12;
	x = 200;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	while (++i < vm.count_players)
	{
		mvprintw(y, x, "Player %-2d :", vm.players[i].id * (-1));
		attron(COLOR_PAIR(green + i));
		mvprintw(y, 212, "%.41s", vm.players[i].prog_name);
		attroff(COLOR_PAIR(green + i));
		mvprintw(y + 1, x + 2, "Last live :");
		mvprintw(y + 2, x + 2, "Lives in current period :");
		y += 4;
	}
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

static void	static_submenu_bottom(void)
{
	int y;
	int x;

	y = 50;
	x = 200;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	mvprintw(y, x, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvprintw(y + 2, x, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(y + 4, x, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(y + 6, x, "MAX_CHECKS : %d", MAX_CHECKS);
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

void		init_window(t_machine *vm, t_graf *graf)
{
	*graf = (t_graf) {1, 50};
	initscr();
	noecho();
	curs_set(0);
	init_pairs();
	draw_border();
	print_graph_arena(*vm);
	print_pc_arena(*vm);
	static_submenu_top(*vm, *graf, 0);
	print_static_players(*vm);
	dynamic_players(*vm);
	static_submenu_bottom();
	pause_occurrent(vm, graf);
}
