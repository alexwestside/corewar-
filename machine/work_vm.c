
#include "machine.h"

void	init_arena_vm(t_machine vm)
{
	int i;
	int size;
	int size_pl;
	t_tasks	*tmp;

	i = -1;
	size = MEM_SIZE / vm.count_players;
	while (++i < vm.count_players)
	{
		size_pl = size * (i + 1);
		if (size_pl + vm.size_code_players[i] > MEM_SIZE)
			break ;
		ft_memcpy(vm.arena + size_pl, vm.code_players[i], vm.size_code_players[i]);
		tmp = create_task(create_fork(-(i + 1), size_pl), op[17], 0);
		add_top(vm.top, vm.buttom, tmp);
	}
	// debug
	if (i != vm.count_players)
		ft_printf("/n/nError to init arena vm index %d %d > %d/n/n", i, size_pl + vm.size_code_players[i], MEM_SIZE);
}

void	run_vm(t_machine vm)
{
	unsigned	i;
	int			j;
	t_tasks		*node;

	i = -1;
	j = -1;
	init_arena_vm(&vm);
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