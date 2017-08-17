
#include "machine.h"

/*
**  init pairs
**  100  border
*/

void        init_pairs(void)
{
	if (!has_colors())
	{
		endwin();
		ft_printf("Colors doesnt support");
		exit(1);
	}
	start_color();
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
    init_pair(cyan, COLOR_CYAN, COLOR_BLACK);
	init_pair(un_byte, 240, COLOR_BLACK);
	init_pair(pc_green, COLOR_BLACK, COLOR_GREEN);
	init_pair(pc_blue, COLOR_BLACK, COLOR_BLUE);
	init_pair(pc_red, COLOR_BLACK, COLOR_RED);
	init_pair(pc_cyan, COLOR_BLACK, COLOR_CYAN);
	init_pair(pc_un_byte, 240, 240);
	init_pair(100, 240, 240);
	init_pair(w_text, COLOR_WHITE, COLOR_BLACK);

}

void        dynamic_players(t_machine vm)
{
	int			y;
	int			x;
	unsigned	i;

	i = -1;
	y = 13;
	x = 221;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	while (++i < vm.count_players)
	{
		mvprintw(y, x + 3, "%10u", vm.players[i].last_live);
		mvprintw(y + 1, x + 5, "%8u", vm.players[i].count_live);
		y += 4;
	}
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

static void dynamic_submenu_top(t_machine vm, t_graf graf, int cycle)
{
	int y;
	int x;

	y = 5;
	x = 222;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	mvprintw(y, x, "%-4.0f", graf.speed);
	y += 3;
	mvprintw(y, x - 14, "%-20u", cycle);
	y += 2;
	mvprintw(y, x - 10, "%-20u", vm.count_forks);
	y = 50;
	mvprintw(y, x - 7, "%-4d", vm.cycle_to_die);
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

void        graph_is_winner(t_machine vm)
{
	int y;
	int x;
	int winner;

	y = 33;
	x = 200;
	winner = vm.won_player;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	mvprintw(8, 222 - 14, "%-20u", vm.cycle);
	mvprintw(y, x, "The winner is : ");
	attron(COLOR_PAIR(green + winner));
	mvprintw(y, x + 16, "%s", vm.players[winner].prog_name);
	attroff(COLOR_PAIR(green + winner));
	mvprintw(y + 2, x, "Press any key to finish");
	attroff(COLOR_PAIR(w_text) | A_BOLD);
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}

void        graph_main(t_machine vm, t_graf *grap)
{
    dynamic_submenu_top(vm, *grap, vm.cycle);
    dynamic_players(vm);
    print_graph_arena(vm);
    print_pc_arena(vm);
    key_occurrent(&vm, grap);
}
