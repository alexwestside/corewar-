/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:14:18 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 13:14:24 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	format_player(char *fmt_st, char *fmt_end, const char *str)
{
	ft_putstr(fmt_st);
	ft_putstr(str);
	ft_putstr(fmt_end);
}

void	head_print(t_machine vm)
{
	unsigned i;
	int 	num_player;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm.count_players)
	{
		num_player = vm.players[i].id;
		num_player *= num_player < 0 ? -1 : 1;
		ft_printf("%c Player %u, weighing %u bytes, ", '*', num_player, vm.players[i].prog_size);
		format_player("\"", "\"", vm.players[i].prog_name);
		ft_putchar(' ');
		format_player("(\"", "\")", vm.players[i].comment);
		ft_putstr(" !\n");
	}
}

//void	test_print_code_player(t_machine vm)
//{
//	size_t  i;
//	unsigned j;
//
//	i = -1;
//	j = -1;
//	while (++j < vm.count_players)
//	{
//		i = -1;
//		ft_printf("\n\n size code player [%u]\n", vm.players[j].prog_size);
//		ft_printf("\n\n byte code player [%d]\n", j);
//		while (++i < vm.players[j].prog_size)
//		{
//			ft_printf(" %02x", vm.players[j].code[i]);
//		}
//		ft_putchar('\n');
//	}
//}

void	console_print_arena(t_machine vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((i % PR_SIZE_ARENA) == 0)
			ft_printf("\n0x%04x :", i);
		ft_printf(" %02x", vm.arena[i]);
	}
	ft_putchar('\n');
}

void	is_winner(t_machine vm)
{
	int won;

	won = vm.players[vm.won_player].id;
	won *= won < 0 ? -1 : 1;
	ft_printf("Contestant %d, \"%s\", has won !\n", won,
			  vm.players[vm.won_player].prog_name);
}
