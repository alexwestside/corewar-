//
// Created by Andriy Yatsynyak on 7/8/17.
//


// ВАЖЛИВО не запускати

#include <stdlib.h>
#include "machine.h"
#include "ncurses.h"
#define PR_SIZE_ARENA 0x0040
#define MEM_SIZE 4096


//typedef struct		s_cord
//{
//	int 	y;
//	int 	x;
//}			t_cord;

//typedef struct s_win
//{
//	t_cord	status;
//	t_cord	sec_limit;
//	t_cord	cycle;
//	t_cord	processes;
//	t_cord	cycle_to_die;
//	t_cord	cycle_delta;
//	t_cord	nbr_live;
//	t_cord	max_checks;
//}			t_win;


void	console_print_arena(unsigned char *vm)
{
	int i;
	int y;

	i = -1;
	y = 2;
	move(1, 3);
	while (++i < MEM_SIZE)
	{
		if ((i % PR_SIZE_ARENA) == 0)
			move(y++, 3);
		printw(" %02x", vm[i]);
	}
}


void	init_pairs(void)
{
	if (!has_colors())
	{
		endwin();
		printf("Цвета не поддерживаются");
		exit(1);
	}
	start_color();
	use_default_colors();
	init_pair(5, COLOR_WHITE, COLOR_BLACK);		// sub menu
	init_pair(6, 240, COLOR_BLACK);				// arena
	init_pair(10, 240, 240);					// border
}


void	draw_border(void)
{
	char sing;
	int height;
	int width;

	sing = '*';
	height = 68;
	width = 254;
	attron(COLOR_PAIR(10));
	vline(sing, height - 1);
	hline(sing, width);
	move(height - 1, 0);
	hline(sing, width);
	move(0, width);
	vline(sing, height);
	move(0, 197);
	vline(sing, height);
	attroff(COLOR_PAIR(10));
}

void	def_submenu_top(int process)
{
	int y;
	int x;

	y = 3;
	x = 197 + 3;
	attron(COLOR_PAIR(5) |A_BOLD);
	mvprintw(y, x, "** PAUSED **");
	mvprintw(y + 2, x, "Cycles/second limit : 50");
	mvprintw(y + 5, x, "Cycle : 0");
	mvprintw(y + 7, x, "Processes : %d", process);
	attroff(COLOR_PAIR(5) |A_BOLD);
}

void	static_submenu_bottom(void)
{
	int y;
	int x;

	y = 50;
	x = 197 + 3;
	attron(COLOR_PAIR(5) |A_BOLD);
	mvprintw(y, x, "CYCLE_TO_DIE : %d", 1536);
	mvprintw(y + 2, x, "CYCLE_DELTA : %d", 50);
	mvprintw(y + 4, x, "NBR_LIVE : %d", 21);
	mvprintw(y + 6, x, "MAX_CHECKS : %d", 10);
	attroff(COLOR_PAIR(5) |A_BOLD);
}


//int main(void)
//{
//	unsigned char vm[MEM_SIZE];
//
//	initscr();
//	noecho(); 			//Не печатать на экране то, что набирает пользователь на клавиатуре
//	curs_set(0);		//Убрать курсор
//	init_pairs();
//	draw_border();
//	attron(COLOR_PAIR(6) |A_BOLD);
//	console_print_arena(vm);
//	attroff(COLOR_PAIR(6) | A_BOLD);
//	def_submenu_top(1);
//	static_submenu_bottom();
//	move(10, 20);
//	refresh();
//	getch();
//	endwin();
//	return (0);
//}