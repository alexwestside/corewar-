/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:08:12 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 15:08:15 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

static void	copy_flags(char **argv, int argc, int i, t_flags *flags)
{
	char *tmp;

	tmp = argv[i];
	flags->flag = *(tmp + 1);
	if (!ft_strcmp(argv[i], "-g") || !ft_strcmp(argv[i], "-a"))
		return ;
	if (i + 1 < argc && is_number(argv[i + 1]))
		flags->number = ft_atoi(argv[i + 1]);
	else
		print_usage();
	if (flags->flag == 'v' && flags->number > 2)
		print_usage();
}

t_flags		get_flags(int argc, char **argv)
{
	int		i;
	t_flags	flags;

	i = 0;
	ft_memset(&flags, 0, sizeof(flags));
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-g") ||
				!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-a"))
			i == 1 ? copy_flags(argv, argc, i, &flags) : print_usage();
		else if (!ft_strcmp(argv[i], "-n"))
		{
			if (i + 1 < argc && is_number(argv[i + 1]))
				continue ;
			else
				print_usage();
		}
	return (flags);
}
