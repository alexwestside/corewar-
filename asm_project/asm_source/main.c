/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 17:06:33 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/29 21:09:02 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

void			copy_method(t_command *command, char ***checkdup)
{
	int 		i;

	i = 0;
	while (command)
	{
		command->method ? i++ : 0;
		command = command->next;
	}
	i++;
	*checkdup = (char **)malloc(sizeof(char *) * (i));
	(*checkdup)[i--] = NULL;
	while(i--)
		(*checkdup)[i] = "1";
}

unsigned int	*valid(char **text, t_corewar *corewar)
{
	char	*name;
	char	*comment;

	corewar->bot.command = NULL;
	corewar->bot.hash_table = (t_hash_table **)malloc(sizeof(t_hash_table *));
	corewar->bot.keys = (unsigned int *)malloc(sizeof(unsigned int));
	ft_name_comment(&name, &comment, &text);
	corewar->bot.keys = ft_command(text, 0, &corewar->bot);
	copy_method(corewar->bot.command, &corewar->bot.checkdup);
	if (ft_strlen(name) > PROG_NAME_LENGTH)
	{
		ft_printf("Length name should not be more %d characters!!!", PROG_NAME_LENGTH);
		exit(0);
	}
	if (ft_strlen(comment) > COMMENT_LENGTH)
	{
		ft_printf("Length comment should not be more %d characters!!!", COMMENT_LENGTH);
		exit(0);
	}
	corewar->bot.comment = comment;
	corewar->bot.name = name;
	return (corewar->bot.keys);
}

char	**open_read(char *av)
{
	int		fd;
	char	*str;
	char	*s;

	fd = open(av, O_RDONLY);
	s = "";
	if (fd <= 0)
	{
		ft_printf("INVALID FILE");
		exit(0);
	}
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
	corewar.bot.keys = valid(text, &corewar);
	ft_asm(&corewar);
}
