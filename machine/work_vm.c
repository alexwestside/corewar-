
#include "machine.h"

void	init_arena_vm(t_machine *vm)
{
	int i;
	int size;
	int size_pl;

	i = -1;
	size = MEM_SIZE / vm->count_players;
	while (++i < vm->count_players)
	{
		size_pl = size * i;
//		if (size_pl + vm->size_code_players[i] > MEM_SIZE)
//			break ;
		ft_memcpy(vm->arena + size_pl, vm->code_players[i], vm->size_code_players[i]);
        add_before(&vm->head_lst, create_fork(-(i + 1), size_pl));
	}
	// debug
//	if (i != vm->count_players)
//		ft_printf("/n/nError to init arena vm index %d %d > %d/n/n", i, size_pl + vm->size_code_players[i], MEM_SIZE);
}



//void	run_vm(t_machine vm)
//{
//	unsigned	i;
//	int			j;
//	t_tasks		*node;
//
//	i = 0;
//	j = -1;
//	init_arena_vm(&vm);
//	init_forks(&vm, 0);
//	while (vm.cycle_to_die_now > 0)
//	{
//		while (++i <= vm.cycle_to_die_now || j < MAX_CHECKS)
//		{
//			init_forks(&vm, i);
//			working_forks(&vm, i);
//			//todo remember when forks save life for player and vm.count_life += 1
//			//todo check task is faled operation or byte '00' move to task_zombi
//		}
//		//todo check life forks
//		//todo del forks ho dont life
//		if (vm.head_lst == NULL)
//			break ;
//		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? vm.cycle_to_die_now += (vm.cycle_to_die -= CYCLE_DELTA) : j++;
//		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? j = 0 : 0;
//	}
//}


void    check_forks(t_machine *vm, unsigned cycle)
{
    int     cmd;
    t_fork *iter;

    iter = vm->head_lst;
    while (iter)
    {
        if (iter->mod == 1 && iter->time_cycle && cycle == iter->time_cycle)
        {
            handling_args(iter->cmd - 1, vm, iter);
            iter->mod = 0;
        }
        else if (iter->mod == 0)
        {
            cmd = (int)vm->arena[move_pc(iter->pc)];
            if (0 < cmd < 17)
            {
                iter->cmd = cmd;
                iter->mod = 1;
                iter->time_cycle = cycle + g_op_tab[cmd - 1].cycles;
            }
            else
                iter->pc = move_pc(iter->pc + 1);
        }
        iter->next;
    }
}


void	run_vm(t_machine *vm)
{
	unsigned	i;
	int 		j;

	i = 0;
	j = -1;
	init_arena_vm(vm);
    console_print_arena(*vm);
	while (vm->head_lst)
	{
        check_forks(vm, i);
        i++;
        console_print_arena(*vm);
	}


}