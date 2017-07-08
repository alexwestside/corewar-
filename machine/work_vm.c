
#include "machine.h"

void	init_arena_vm(t_machine vm)
{
	int i;
	int size;
	int size_pl;

	i = -1;
	size = MEM_SIZE / vm.count_players;
	while (++i < vm.count_players)
	{
		size_pl = size * (i + 1);
		if (size_pl + vm.size_code_players[i] > MEM_SIZE)
			break ;
		ft_memcpy(vm.arena + size_pl, vm.code_players[i], vm.size_code_players[i]);
		add_forks(&vm.head_lst, create_fork(-(i + 1), vm.arena + size_pl));
	}
	// debug
	if (i != vm.count_players)
		ft_printf("/n/nError to init arena vm index %d %d > %d/n/n", i, size_pl + vm.size_code_players[i], MEM_SIZE);
}


//int 	init_zombi_tasks(t_machine vm)
//{
//	unsigned char tmp;
//	t_forks *p;
//
//	p = vm.head_lst;
//	while (p)
//	{
//		add_top(vm.top_zombi, vm.buttom_zombi, p);
//		p = p->next;
//	}
//	return (0);
//}
//
//t_tasks	*get_task(t_tasks *node)
//{
//	t_tasks *tmp;
//
//	if (node->next == NULL)
//	{
//		tm
//	}
//		tmp = node;
//
//	tmp->next = node->next->next;
//	tmp->prev = node->prev;
//	node->prev = NULL;
//	node->next = NULL;
//	return (node);
//}


int		respodile_task(t_machine vm, unsigned cycle)
{
	t_tasks *p_zombi;
	t_tasks *tmp;

	p_zombi = vm.top_zombi;
	while (p_zombi)
	{
		tmp = *(vm.arena + p_zombi->p_fork->node.pc);
		if (tmp < 17)
		{
			p_zombi->time_cycle = op[tmp][5] + cycle;
			tmp = p_zombi;
			push(vm.top, vm.buttom, get_task(tmp));
		}
		p_zombi = p_zombi->next;
	}
}

void	init_forks(t_machine vm, unsigned cycle)
{
	t_forks			*iter;
	unsigned char	tmp;

	min = MAX_INT;
	iter = vm.head_lst;
	while (iter)
	{
		tmp = *(vm.arena + iter->node.pc);
		if (tmp < 17 && tmp.mod == 0)
		{
			iter->time_cycle = op[tmp][5] + cycle;
			iter->mod = 1;
		}
		else
			tmp.mod = -1;
		iter = iter->next;
	}
}


void	working_forks(t_machine vm, unsigned cycle)
{
	t_forks *iter;

	iter = vm.head_lst;
	while (iter)
	{
		if (iter->mod == -1)
			iter->node.pc = cycle % MEM_SIZE;
		else if (iter->mod == 1 && iter->time_cycle == cycle)
			//todo working operation
		iter = iter->next;
	}
}



void	run_vm(t_machine vm)
{
	unsigned	i;
	int			j;
	t_tasks		*node;

	i = 0;
	j = -1;
	init_arena_vm(&vm);
	init_forks(&vm, 0);
	while (vm.cycle_to_die_now > 0)
	{
		while (++i <= vm.cycle_to_die_now || j < MAX_CHECKS)
		{
			init_forks(&vm, i);
			working_forks(&vm, i);
			//todo remember when forks save life for player and vm.count_life += 1
			//todo check task is faled operation or byte '00' move to task_zombi
		}
		//todo check life forks
		//todo del forks ho dont life
		if (vm.head_lst == NULL)
			break ;
		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? vm.cycle_to_die_now += (vm.cycle_to_die -= CYCLE_DELTA) : j++;
		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? j = 0 : 0;
	}
}