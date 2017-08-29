/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 17:06:33 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/29 13:16:35 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

void	valid(char **text, t_corewar *corewar)
{
	char	*name;
	char	*comment;
	t_bot	bot;

	bot.command = NULL;
	bot.hash_table = (t_hash_table **)malloc(sizeof(t_hash_table *));
	bot.keys = (unsigned int *)malloc(sizeof(unsigned int));
	ft_name_comment(&name, &comment, &text);
	corewar->bot = ft_command(text, 0, bot);
	corewar->bot.name = name;
	corewar->bot.comment = comment;
}

char	**open_read(char *av)
{
	int		fd;
	char	*str;
	char	*s;

	fd = open(av, O_RDONLY);
	s = "";
	while (get_next_line(fd, &str) != 0)
	{
		s = ft_strjoin(s, str);
		s = ft_strjoin(s, "\n");
	}
	return (ft_strsplit(s, '\n'));
}

int		main(int ac, char **av)
{
	char		**text;
	t_corewar	corewar;

	(void)ac;
	text = open_read(av[1]);
	valid(text, &corewar);
	ft_asm(&corewar);
}
