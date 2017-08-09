//
// Created by Andriy Yatsynyak on 7/8/17.
//


// ВАЖЛИВО не запускати

#include <stdlib.h>
#include "machine.h"
#include <ncurses.h>
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


void	print_graf_arena(t_machine *vm)
{
	int i;
	int y;

	i = -1;
	y = 2;
	move(1, 3);
	attron(COLOR_PAIR(6) |A_BOLD);
	while (++i < MEM_SIZE)
	{
		if ((i % PR_SIZE_ARENA) == 0)
			move(y++, 3);
		printw(" %02x", vm->arena[i]);
	}
	attroff(COLOR_PAIR(6) | A_BOLD);
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

void	def_submenu_top(t_machine *vm, t_graf *graf, int cycle)
{
	int y;
	int x;

	y = 3;
	x = 197 + 3;
	attron(COLOR_PAIR(5) |A_BOLD);
	if (graf->pause == 1)
		mvprintw(y, x, "** PAUSED **");
	else
		mvprintw(y, x, "** RUNNING **");
	mvprintw(y + 2, x, "Cycles/second limit : %f", graf->speed);
	mvprintw(y + 5, x, "Cycle : %d", cycle);
	mvprintw(y + 7, x, "Processes : %u", vm->count_forks);
	attroff(COLOR_PAIR(5) | A_BOLD);
}

void	static_submenu_bottom(void)
{
	int y;
	int x;

	y = 50;
	x = 197 + 3;
	attron(COLOR_PAIR(5) |A_BOLD);
	mvprintw(y, x, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvprintw(y + 2, x, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(y + 4, x, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(y + 6, x, "MAX_CHECKS : %d", MAX_CHECKS);
	attroff(COLOR_PAIR(5) |A_BOLD);
}

void	init_graf(t_graf *graf)
{
	graf->pause = 1;
	graf->print = 0;
	graf->speed = 50;
}

void	init_window(t_machine *vm, t_graf *graf)
{
	init_graf(graf);
	initscr();
	noecho(); 			//Не печатать на экране то, что набирает пользователь на клавиатуре
	curs_set(0);		//Убрать курсор
	init_pairs();
	draw_border();
	print_graf_arena(vm);
	def_submenu_top(vm, graf, 0);
	static_submenu_bottom();
	refresh();
	getch();
	endwin();
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
//
//	def_submenu_top(vm);
//	static_submenu_bottom();
//	move(10, 20);
//	refresh();
//	getch();
//	endwin();
//	return (0);
//}