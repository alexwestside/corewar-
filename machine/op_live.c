

#include "machine.h"


void    op_live(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    unsigned i;
//    t_player tmp;

    i = -1;
    fork->life = 1;
    vm->count_live++;
    while (++i < vm->count_players)
        if (vm->players[i].id == args[0])
        {
//            tmp = vm->players[i];
            vm->won_player = i;
            vm->players[i].count_live++;
            vm->players[i].last_live = vm->cycle;
            return ;
        }
}