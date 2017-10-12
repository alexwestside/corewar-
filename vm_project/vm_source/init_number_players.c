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

static int		check_valid_is_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1 || read(fd, 0, 0) == -1)
	{
		fd != -1 ? close(fd) : 0;
		return (0);
	}
	close(fd);
	return (1);
}

/*
**  num doesnt be 0
*/

static void		set_query_number(t_machine *vm, int index)
{
	int			j;
	unsigned	i;

	j = 1;
	while (j <= (int)vm->count_players)
	{
		i = -1;
		while (++i < vm->count_players && j <= (int)vm->count_players)
			if (vm->players[i].id == j)
				j++;
			else
			{
				vm->players[index].id = j;
				return ;
			}
	}
}

static void		set_number(t_machine *vm, int index, int num)
{
	unsigned	i;

	i = -1;
	if (num > (int)vm->count_players || num <= 0)
		error_exit(NULL, 10, vm);
	while (++i < vm->count_players)
		if (vm->players[i].id == num)
			error_exit(NULL, 10, vm);
	if (num && vm->players[index].id == 0)
		vm->players[index].id = num;
}

void			init_number_players(t_machine *vm, int argc, char **argv)
{
	int			i_arg;
	unsigned	j_players;

	i_arg = 0;
	j_players = -1;
	while (++i_arg < argc)
		if (!ft_strcmp(argv[i_arg], "-n"))
		{
			if (i_arg + 1 < argc && is_number(argv[i_arg + 1]) &&
					i_arg + 2 < argc && check_valid_is_file(argv[i_arg + 2]))
			{
				if (j_players + 1 < vm->count_players)
					set_number(vm, ++j_players, ft_atoi(argv[i_arg + 1]));
				i_arg += 2;
			}
			else
				error_exit(NULL, 10, vm);
		}
		else if (check_valid_is_file(argv[i_arg]))
			if (j_players + 1 < vm->count_players)
				set_query_number(vm, ++j_players);
}
