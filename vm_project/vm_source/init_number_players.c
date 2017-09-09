/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number_players.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:05:34 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 21:05:44 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

static int	check_valid_is_file(char **str, int index, int len_str, int mod)
{
	int fd;

	index += mod == 1 ? 1 : 0;
	if (index >= len_str)
		return (0);
	fd = open(str[index], O_RDONLY);
	if (fd == -1 || read(fd, 0, 0) == -1)
		return (0);
	return (1);
}

/*
**  num doesnt be 0
*/

static void	set_number(t_machine *vm, int index, int num)
{
	int			min;
	unsigned	i;
	unsigned	j;

	i = -1;
	while (++i < vm->count_players)
		if (vm->players[i].id == num)
		{
			j = -1;
			min = INT_MAX;
			while (++j < vm->count_players)
				if (vm->players[j].id < min)
					min = vm->players[j].id;
			vm->players[index].id = min < 0 ? min - 1 : -1;
			break ;
		}
	if (num && vm->players[index].id == 0)
		vm->players[index].id = num;
}

void		init_number_players(t_machine *vm, int argc, char **argv)
{
	int			num;
	int			i_arg;
	unsigned	j_players;

	num = 0;
	i_arg = 0;
	j_players = -1;
	while (++i_arg < argc)
		if (!ft_strcmp(argv[i_arg], "-n"))
		{
			if (i_arg + 1 < argc && is_number(argv[++i_arg]) &&
				check_valid_is_file(argv, i_arg, argc, 1))
			{
				num = ft_atoi(argv[i_arg]);
				if (j_players + 1 < vm->count_players)
					set_number(vm, ++j_players, num);
			}
		}
		else if (check_valid_is_file(argv, i_arg, argc, 0))
			if (j_players + 1 < vm->count_players)
				set_number(vm, ++j_players, num);
}
