
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
        vm->count_forks++;
        if (vm->flags.flag == 'g')
            ft_memset(vm->color_arena + size_pl, i + 1, vm->players[i].prog_size);
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
    unsigned i;
//    t_player tmp;

    i = -1;
    vm->iter_max_checks++;
    if (vm->count_live >= NBR_LIVE || vm->iter_max_checks == MAX_CHECKS)
    {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->iter_cycle_to_die = vm->cycle + vm->cycle_to_die;
        vm->iter_max_checks = 0;
        while (++i < vm->count_players)
        {
//            tmp = vm->players[i];
            vm->players[i].count_live = 0;
            vm->players[i].last_live = 0;
        }
//        ft_printf("cycle to die %d cycle %u count_live %u  last live %us\n", vm->cycle_to_die, debug_cicle, vm->count_live, vm->players[0].last_live);
    }
    vm->count_live = 0;
    vm->iter_cycle_to_die = vm->cycle + vm->cycle_to_die;
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
        ft_printf("fork pc %u id %d reg[0] %d \n", tmp->pc, tmp->id, tmp->reg[0]);
        tmp = tmp->next;
    }
}

void    print_players(t_machine vm)
{
    unsigned i;

    i = -1;
    while (++i < vm.count_players)
    {
        ft_printf("players iter %d id player %d\n", i, vm.players[i].id);
    }
}

void	run_vm(t_machine *vm)
{
    t_graf      graf;

	init_arena_vm(vm);
    vm->flags.flag == 'g' ? init_window(vm, &graf) : 0;
//    print_forks(vm->head_lst);
//    print_players(*vm);
	while (vm->head_lst && vm->cycle_to_die >= 0)
	{
        check_forks(vm, vm->cycle);
        if (vm->cycle == (unsigned)vm->iter_cycle_to_die)
            cycle_to_die(vm);
        if (vm->flags.flag == 'd')
        {
            console_print_arena(*vm);
            release_memory(vm);
            exit(0);
        }
        vm->flags.flag == 'g' ? graph_main(*vm, &graf) : 0;
        vm->cycle++;
	}
    vm->flags.flag == 'g' ? graph_is_winner(*vm) : is_winner(*vm);
    release_memory(vm);
}