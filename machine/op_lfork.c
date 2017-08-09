

#include "machine.h"


void    op_lfork(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
    t_fork *tmp;

    tmp = create_fork(0, 0);
    add_before(&vm->head_lst, tmp);
    inheritance(tmp, fork, args[0]);
    vm->count_forks++;
}
