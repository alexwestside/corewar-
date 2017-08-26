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

static void	format_player(char *fmt_st, char *fmt_end, const char *str)
{
	ft_putstr(fmt_st);
	ft_putstr(str);
	ft_putstr(fmt_end);
}

void		head_print(t_machine vm)
{
	unsigned	i;
	int			num_player;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm.count_players)
	{
		num_player = vm.players[i].id;
		num_player *= num_player < 0 ? -1 : 1;
		ft_printf("%c Player %u, weighing %u bytes, ", '*', num_player,
		vm.players[i].prog_size);
		format_player("\"", "\"", vm.players[i].prog_name);
		ft_putchar(' ');
		format_player("(\"", "\")", vm.players[i].comment);
		ft_putstr(" !\n");
	}
}

void		console_print_arena(t_machine vm)
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

void		is_winner(t_machine vm)
{
	int won;

	won = vm.players[vm.won_player].id;
	won *= won < 0 ? -1 : 1;
	ft_printf("Contestant %d, \"%s\", has won !\n", won,
	vm.players[vm.won_player].prog_name);
}

void		print_usage(void)
{
	ft_putendl("Usage: ./corewar [-dump nbr_cycles | -v N | -a | -g] "
	"[[-n number] champion1.cor] ...");
	ft_putendl("    -a        : Prints output from \"aff\" "
	"(Default is to hide it)");
	ft_putendl("    -n N      : sets the number of the player. "
	"If non-existent, the player will have the next"
	"\n\t\tavailable number in the order of the parameters (Default start: -1)."
	" If there"
	"\n\t\tis a given N or whether the number is zero, the player will be "
	"given the smallest\n\t\tnegative number from the existing players");
	ft_putendl("#### TEXT OUTPUT MODE #####################################"
	"#########################################");
	ft_putendl("    -dump N   : Dumps memory after N cycles then exits");
	ft_putendl("    -v N      : Verbosity levels, can be added together "
	"to enable several");
	ft_putendl("                - 0 : Show only essentials");
	ft_putendl("                - 1 : Show lives");
	ft_putendl("                - 2 : Show cycles");
	ft_putendl("#### NCURSES OUTPUT MODE #####################################"
	"######################################");
	ft_putendl("    -g        : Ncurses output mode");
	ft_putendl("##############################################################"
	"######################################");
	exit(0);
}
