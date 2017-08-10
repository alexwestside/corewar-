
#include "machine.h"
#include <ncurses.h>


void	print_byte_code(t_machine vm, unsigned iter, int mod)
{
	int x;
	int y;
	int color;

	x = 3;
	y = 2;
	y =  iter / 64 + y;
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

void	print_graf_arena(t_machine vm)
{
	unsigned i;

	i = 0;
	while (i < MEM_SIZE)
	{
		print_byte_code(vm, i, 0);
		i++;
	}
}

void	print_pc_arena(t_machine vm)
{
	t_fork *iter;

	iter = vm.head_lst;
	while (iter)
	{
		print_byte_code(vm, iter->pc, 1);
		iter = iter->next;
	}
}

void	init_pairs(void)
{
	if (!has_colors())
	{
		endwin();
		ft_printf("Colors doesnt support");
		exit(1);
	}
	start_color();
//	use_default_colors();
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
    init_pair(cyan, COLOR_CYAN, COLOR_BLACK);
	init_pair(un_byte, 240, COLOR_BLACK);				// arena
	init_pair(pc_green, COLOR_BLACK, COLOR_GREEN);
	init_pair(pc_blue, COLOR_BLACK, COLOR_BLUE);
	init_pair(pc_red, COLOR_BLACK, COLOR_RED);
	init_pair(pc_cyan, COLOR_BLACK, COLOR_CYAN);
	init_pair(pc_un_byte, 240, 240);
	init_pair(100, 240, 240);					    // border
	init_pair(w_text, COLOR_WHITE, COLOR_BLACK);

}

void	draw_border(void)
{
	char sing;
	int height;
	int width;

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

void	static_submenu_top(t_machine vm, t_graf graf, unsigned cycle)
{
	int y;
	int x;

	y = 3;
	x = 197 + 3;
	attron(COLOR_PAIR(w_text) | A_BOLD);
//	mvprintw(y, x, "** PAUSED **");
	 mvprintw(y + 2, x, "Cycles/second limit : %.0f", graf.speed);
	mvprintw(y + 5, x, "Cycle : %u", cycle);
	mvprintw(y + 7, x, "Processes : %u", vm.count_forks);
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

void	print_static_players(t_machine vm)
{
	int y;
	int x;
	unsigned i;

	i = -1;
	y = 12;
	x = 200;
	attron(COLOR_PAIR(w_text) | A_BOLD);
	while (++i < vm.count_players)
	{
		mvprintw(y, x, "Player %-2d :", vm.players[i].id);
		attron(COLOR_PAIR(green + i));
		mvprintw(y, 212, "%.41s", vm.players[i].prog_name);
		attroff(COLOR_PAIR(green + i));
		mvprintw(y + 1, x + 2, "Last live :");
		mvprintw(y + 2, x + 2, "Lives in current period :");
		y += 4;
	}
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

void	dynamic_players(t_machine vm)
{
	int y;
	int x;
	unsigned i;

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

void	dynamic_submenu_top(t_machine vm, t_graf graf, int cycle)
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

void	static_submenu_bottom(void)
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

void	init_window(t_machine *vm, t_graf *graf)
{
	*graf = (t_graf){1, 50};
	initscr();
	noecho(); 			//Не печатать на экране то, что набирает пользователь на клавиатуре
	curs_set(0);		//Убрать курсор
	init_pairs();
	draw_border();
	print_graf_arena(*vm);
	print_pc_arena(*vm);
	static_submenu_top(*vm, *graf, 0);
	print_static_players(*vm);
	dynamic_players(*vm);
	static_submenu_bottom();
    pause_event(vm, graf);
}

void	graphic_main(t_machine vm, t_graf *grap)
{
	dynamic_submenu_top(vm, *grap, vm.cycle);
	dynamic_players(vm);
	print_graf_arena(vm);
	print_pc_arena(vm);
    key_event(&vm, grap);
}

void	grah_is_winner(t_machine vm)
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
