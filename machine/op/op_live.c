

#include "../machine.h"


void    op_live(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    int i;

    i = -1;
    fork->life = 1;
    vm->count_live++;
    while (++i < vm->count_players)
        if (vm->players[i].id == args[0])
        {
            vm->won_player = i;
            vm->players[i].count_live++;
            vm->players[i].last_live = debug_cicle;
            return ;
        }
}
