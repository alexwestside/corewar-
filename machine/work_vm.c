
#include "machine.h"

void	init_arena_vm(t_machine *vm)
{
    unsigned i;
	int size;
	int size_pl;

	i = -1;
	size = MEM_SIZE / vm->count_players;
	while (++i < vm->count_players)
	{
		size_pl = size * i;
//		if (size_pl + vm->size_code_players[i] > MEM_SIZE)
//			break ;
		ft_memcpy(vm->arena + size_pl, vm->players[i].code, vm->players[i].prog_size);
        add_before(&vm->head_lst, create_fork(vm->players[i].id, size_pl));
        vm->players[i].id = -(i + 1);
        vm->count_forks++;
	}
	// debug
//	if (i != vm->count_players)
//		ft_printf("/n/nError to init arena vm index %d %d > %d/n/n", i, size_pl + vm->size_code_players[i], MEM_SIZE);
}

void    debug(t_machine vm, unsigned cycle)
{

    ft_printf("\n\ndebug mode %u\n\n", cycle);
    console_print_arena(vm);

    t_fork *iter;

    iter = vm.head_lst;
    while (iter)
    {
        ft_printf("/npc: %u/n", iter->pc);
        iter = iter->next;
    }
}

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
//            debug(*vm, cycle);
            iter->mod = 0;
        }
        if (iter->mod == 0)
        {
            cmd = (int)vm->arena[move_pc(iter->pc)];
            if (0 < cmd && cmd < 17)
            {
                iter->cmd = cmd;
                iter->mod = 1;
                iter->time_cycle = cycle + g_op_tab[cmd - 1].cycles;
            }
            else
                iter->pc = move_pc(iter->pc + 1);
        }
        iter = iter->next;
    }
}

void    overwrite_cycle_to_die(t_machine *vm)
{
    vm->iter_max_checks++;
    if (vm->count_live >= NBR_LIVE || vm->iter_max_checks == MAX_CHECKS)
    {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->iter_cycle_to_die = debug_cicle + vm->cycle_to_die;
        vm->iter_max_checks = 0;
//        ft_printf("cycle to die %d cycle %u count_live %u  last live %us\n", vm->cycle_to_die, debug_cicle, vm->count_live, vm->players[0].last_live);
    }
    vm->count_live = 0;
    vm->iter_cycle_to_die = debug_cicle + vm->cycle_to_die;
}

void    cycle_to_die(t_machine *vm)
{
    t_fork *iter;
    t_fork *next;

    iter = vm->head_lst;
    while (iter)
    {
        next = iter->next;
        if (iter->life == 0)
        {
            if (vm->head_lst == iter)
                vm->head_lst = iter->next;
            next ? next->next = iter->next : 0;
            free(iter);
            vm->count_forks--;
        }
        else
            iter->life = 0;
        iter = next;
    }
    overwrite_cycle_to_die(vm);
}

void    print_forks(t_fork *head)
{
    t_fork *tmp;

    tmp = head;
    while (tmp)
    {
        ft_printf("fork pc %d \n", tmp->pc);
        tmp = tmp->next;
    }
}

void	run_vm(t_machine *vm)
{
	unsigned    i;
    t_graf      graf;

	i = 0;
	init_arena_vm(vm);
//    console_print_arena(*vm);
    print_forks(vm->head_lst);
    vm->flags.flag[0] == 'g' ? init_window(vm, &graf) : 0;
	while (vm->head_lst && vm->cycle_to_die >= 0)
	{
        check_forks(vm, i);
        if (i == (unsigned)vm->iter_cycle_to_die)
            cycle_to_die(vm);
        if (vm->flags.flag[0] == 'd')
        {
            console_print_arena(*vm);
            release_memory(vm);
            exit(0);
        }
        i++;
        debug_cicle = i;
	}
    is_winner(*vm);
}