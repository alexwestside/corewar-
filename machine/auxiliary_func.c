/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:58:10 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 14:58:18 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	save_run_fork(t_fork *iter, int cmd)
{
	iter->cmd = cmd;
	iter->time_cycle = g_op_tab[cmd - 1].cycles - 2;
}

void	print_dump(t_machine *vm)
{
	console_print_arena(*vm);
	release_memory(vm);
	exit(0);
}

void	print_flag(t_machine vm, t_player *p, int mod)
{
	int id_player;

	if (vm.flags.flag == '\0')
		return ;
	if (vm.flags.flag == 'v' && vm.flags.number == 2 && mod == -1)
		ft_printf("It is now cycle %u\n", vm.cycle + 1);
	else if (vm.flags.flag == 'v' && vm.flags.number == 2 && mod == 0)
		ft_printf("It is now cycle %u\n", vm.cycle);
	else if (vm.flags.flag == 'v' && vm.flags.number == 2 && mod == 2)
		ft_printf("Cycle to die is now %d\n", vm.cycle_to_die);
	else if (vm.flags.flag == 'v' && vm.flags.number == 1 && mod == 1)
	{
		id_player = p->id < 0 ? p->id * (-1) : 0;
		ft_printf("Player %d (%s) is said to be alive\n", id_player,
		p->prog_name);
	}
}
