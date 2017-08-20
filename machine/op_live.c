

#include "machine.h"


void    op_live(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    unsigned i;
//    t_player tmp;
//    int a[MAX_ARGS_NUMBER];

    i = -1;
    fork->life = 1;
    vm->count_live++;
//    tmp = vm->players[0];
//    a[0] = args[0];
    while (++i < vm->count_players)
        if (vm->players[i].id == args[0])
        {
//            tmp = vm->players[i];
            print_flag(*vm, &vm->players[i], 1);
            vm->won_player = i;
            vm->players[i].count_live++;
            vm->players[i].last_live = (unsigned)vm->cycle;
            return ;
        }
}
