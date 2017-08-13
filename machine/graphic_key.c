

#include "machine.h"

static void		period_occurrent(t_graf *graf)
{
    double	period;

    nodelay(stdscr, TRUE);
    attron(A_BOLD);
    mvprintw(2, 199, "%-13s", "** RUNNING **");
    attroff(A_BOLD);
    period = (1 / graf->speed);
    MSLEEP(period);
}

static void		esc_occurrent(t_machine *vm)
{
	endwin();
	release_memory(vm);
	exit(0);
}

static void		key_switch(int key, t_graf *graf, t_machine *vm)
{
	if (key == SPACE)
		graf->pause ^= 1;
	else if (key == 'q')
		graf->speed -= 10;
	else if (key == 'w')
		graf->speed -= 1;
	else if (key == 'e')
		graf->speed += 1;
	else if (key == 'r')
		graf->speed += 10;
	else if (key == ESC)
		esc_occurrent(vm);
}

void			pause_occurrent(t_machine *vm, t_graf *graf)
{
	int key;

	attron(COLOR_PAIR(w_text) | A_BOLD);
	while (graf->pause == 1)
	{
		nodelay(stdscr, FALSE);
		mvprintw(2, 199, "%-13s", "** PAUSED **");
		key = getch();
		if (key == 's')
			break ;
		key_switch(key, graf, vm);
		if ((int)graf->speed < 5)
			graf->speed = 5;
		if ((int)graf->speed > 1000)
			graf->speed = 1000;
		mvprintw(5, 222, "%-4.0f", graf->speed);
	}
	period_occurrent(graf);
	attroff(COLOR_PAIR(w_text) | A_BOLD);
}

void			key_occurrent(t_machine *vm, t_graf *graf)
{
	int key;

	key = getch();
	if (key == ERR)
		return (pause_occurrent(vm, graf)) ;
	key_switch(key, graf, vm);
	if ((int)graf->speed < 5)
		graf->speed = 5;
	if ((int)graf->speed > 1000)
		graf->speed = 1000;
	pause_occurrent(vm, graf);
}
