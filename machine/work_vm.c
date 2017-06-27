
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


int 	init_zombi_tasks(t_machine vm)
{
	unsigned char tmp;
	t_forks *p;

	p = vm.head_lst;
	while (p)
	{
		add_top(vm.top_zombi, vm.buttom_zombi, p);
		p = p->next;
	}
	return (0);
}

t_tasks	*get_task(t_tasks *node)
{
	t_tasks *tmp;

	if (node->next == NULL)
	{
		tm
	}
		tmp = node;

	tmp->next = node->next->next;
	tmp->prev = node->prev;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}


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

//int 	move_task(t_machine vm)
//{
//	t_tasks *p_zombi;
//	unsigned char tmp;
//
//	p_zombi = vm.
//}



void	swap_tasks(t_machine vm, int mod)
{

}

void	run_vm(t_machine vm)
{
	unsigned	i;
	int			j;
	t_tasks		*node;

	i = -1;
	j = -1;
	init_arena_vm(&vm);
	init_zombi_tasks(&vm);
	while (vm.cycle_to_die_now > 0)
	{
		while (++i <= vm.cycle_to_die_now || j < MAX_CHECKS)
		{
			//todo check task_zombi to fork in operation and move to task
			//todo init forks in working tasks after first check cicle to when run operation comand
			//todo remember when forks save life for player and vm.count_life += 1
			//todo check task is faled operation or byte '00' move to task_zombi
		}
		//todo check life forks
		//todo del forks ho dont life
		if (vm.buttom == NULL && vm.buttom_zombi == NULL)
			break ;
		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? vm.cycle_to_die_now += (vm.cycle_to_die -= CYCLE_DELTA) : j++;
		vm.count_life >= NBR_LIVE || j == MAX_CHECKS ? j = 0 : 0;
	}
}