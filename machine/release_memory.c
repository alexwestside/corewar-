

#include "machine.h"


void    release_memory(t_machine *vm)
{
    int i;

    i = -1;
    if (vm == NULL)
        return ;
    free(vm->arena);
    vm->arena = NULL;
    all_delete(&vm->head_lst);
    vm->head_lst = NULL;
    while (++i < vm->count_players)
    {
        free(vm->players[i].code);
        vm->players[i].code = NULL;
    }
    free(vm->players);
    vm->players = NULL;
}
