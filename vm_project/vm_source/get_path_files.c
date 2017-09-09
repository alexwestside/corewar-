/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:00:52 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 13:01:04 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

/*
** func check_argv check argv when user wrote
**  N - number important
**  1 its return argv a | g | dump N | v N
**  2 its return argv n N
**  3 its return all argv doesnt have first char is '-'
*/

int		check_argv(int num_strs, char **strs, int *i)
{
	if (strs[*i][0] == '-')
	{
		if (!ft_strcmp(strs[*i], "-a") || !ft_strcmp(strs[*i], "-g"))
			return (1);
		else if (!ft_strcmp(strs[*i], "-dump") || !ft_strcmp(strs[*i], "-v"))
		{
			if (*i + 1 < num_strs && is_number(strs[++(*i)]))
				return (1);
			else
				print_usage();
		}
		else if (!ft_strcmp(strs[*i], "-n"))
		{
			if (*i + 1 < num_strs && is_number(strs[++(*i)]))
				return (2);
			else
				print_usage();
		}
		else
			print_usage();
	}
	return (3);
}

void	p_paths(int n, char **argv, char *paths[MAX_PLAYERS], unsigned *count)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	*count = 0;
	while (++i < n)
	{
		if (check_argv(n, argv, &i) != 3)
			continue ;
		fd = open(argv[i], O_RDONLY);
		fd == -1 ? error_exit(argv[i], -1, NULL) : 0;
		(int)read(fd, 0, 0) == -1 ? error_exit(argv[i], -1, NULL) : 0;
		*count += fd != -1 ? 1 : 0;
		close(fd);
		if (*count > MAX_PLAYERS)
			error_exit("\0", -5, NULL);
		j < MAX_PLAYERS ? paths[j++] = argv[i] : 0;
	}
	paths[j] = NULL;
}
