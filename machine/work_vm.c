/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:59:00 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 14:59:04 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	init_arena_vm(t_machine *vm)
{
	int			size;
	int			size_pl;
	unsigned	i;

	i = -1;
	size = MEM_SIZE / vm->count_players;
	while (++i < vm->count_players)
	{
		size_pl = size * i;
		ft_memcpy(vm->arena + size_pl, vm->players[i].code,
		vm->players[i].prog_size);
		add_before(&vm->head_lst, create_fork(vm->players[i].id, size_pl));
		vm->count_forks++;
		if (vm->flags.flag == 'g')
			ft_memset(vm->color_arena + size_pl, i + 1,
			vm->players[i].prog_size);
	}
}

void	check_forks(t_machine *vm)
{
	int		cmd;
	t_fork	*iter;

	iter = vm->head_lst;
	while (iter)
	{
		if (iter->time_cycle == 0)
		{
			handling_args(iter->cmd - 1, vm, iter);
			iter->time_cycle -= 1;
		}
		else if (iter->time_cycle == -1)
		{
			cmd = (int)vm->arena[move_pc(iter->pc)];
			if (0 < cmd && cmd < 17)
				save_run_fork(iter, cmd);
			else
				iter->pc = move_pc(iter->pc + 1);
		}
		else
			iter->time_cycle -= 1;
		iter = iter->next;
	}
}

void	overwrite_cycle_to_die(t_machine *vm)
{
	unsigned i;

	i = -1;
	vm->iter_max_checks++;
	if (vm->count_live >= NBR_LIVE || vm->iter_max_checks == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->iter_cycle_to_die = vm->cycle + vm->cycle_to_die;
		vm->iter_max_checks = 0;
		print_flag(*vm, NULL, 2);
		while (++i < vm->count_players)
		{
			vm->players[i].count_live = 0;
			vm->players[i].last_live = 0;
		}
	}
	vm->count_live = 0;
	vm->iter_cycle_to_die = vm->cycle + vm->cycle_to_die;
}

void	cycle_to_die(t_machine *vm)
{
	t_fork	*iter;
	t_fork	*next;

	iter = vm->head_lst;
	while (iter)
	{
		next = iter->next;
		if (iter->life == 0)
		{
			delete_fork(vm, iter);
			vm->count_forks--;
		}
		else
			iter->life = 0;
		iter = next;
	}
	overwrite_cycle_to_die(vm);
}

void	run_vm(t_machine *vm)
{
	t_graf	graf;

	init_arena_vm(vm);
	vm->flags.flag == 'g' ? init_window(vm, &graf) : head_print(*vm);
	while (vm->head_lst && vm->cycle_to_die >= 0)
	{
		vm->cycle++;
		print_flag(*vm, NULL, 0);
		check_forks(vm);
		if (vm->cycle == vm->iter_cycle_to_die)
			cycle_to_die(vm);
		if (vm->flags.flag == 'd' && vm->flags.number == vm->cycle)
			print_dump(vm);
		vm->flags.flag == 'g' ? graph_main(*vm, &graf) : 0;
	}
	print_flag(*vm, NULL, -1);
	vm->flags.flag == 'g' ? graph_is_winner(*vm) : is_winner(*vm);
	release_memory(vm);
}
