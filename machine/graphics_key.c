

#include "machine.h"
#define MSLEEP(msec) usleep(msec * 1000000.0)
#define SPACE 32
#define ESC 27

void		period_event(t_graf *graf)
{
    double	period;

    nodelay(stdscr, TRUE);
    attron(A_BOLD);
    mvprintw(2, 199, "%-13s", "** RUNNING **");
    attroff(A_BOLD);
    period = (1 / graf->speed);
    MSLEEP(period);
}

void		esc_event(t_machine *vm)
{
    endwin();
    release_memory(vm);
    exit(0);
}

void		pause_event(t_machine *vm, t_graf *graf)
{
    int key;

    while (graf->pause == 1)
    {
        nodelay(stdscr, FALSE);
        mvprintw(2, 199, "%-13s", "** PAUSED **");
        key = getch();
        if (key == SPACE)
            graf->pause ^= 1;
        else if (key == 's')
            break ;
        else if (key == 'q')
            graf->speed -= 10;
        else if (key == 'w')
            graf->speed -= 1;
        else if (key == 'e')
            graf->speed += 1;
        else if (key == 'r')
            graf->speed += 10;
        (key == ESC) ? esc_event(vm) : 0;
        ((int)graf->speed < 5) ? graf->speed = 5 : 0;
        ((int)graf->speed > 1000) ? graf->speed = 1000 : 0;
        mvprintw(4, 221, "%-4.0f", graf->speed);
    }
    period_event(graf);
}

void		key_event(t_machine *vm, t_graf *graf)
{
    int key;

    key = getch();
    if (key == ERR)
        return (pause_event(vm, graf));
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
        esc_event(vm);
    if ((int)graf->speed < 5)
        graf->speed = 5;
    if ((int)graf->speed > 1000)
        graf->speed = 1000;
    pause_event(vm, graf);
}
