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
	int		i;

	i = 0;
	while (command)
	{
		command->method ? i++ : 0;
		command = command->next;
	}
	i++;
	*checkdup = (char **)malloc(sizeof(char *) * (i));
	(*checkdup)[--i] = NULL;
	while (i--)
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
		ft_printf("Length name more than %d characters!!!", PROG_NAME_LENGTH);
		exit(0);
	}
	if (ft_strlen(comment) > COMMENT_LENGTH)
	{
		ft_printf("Length comment more than %d characters!!!", COMMENT_LENGTH);
		exit(0);
	}
	corewar->bot.comment = comment;
	corewar->bot.name = name;
	return (corewar->bot.keys);
}

void			chek_new_line(char *av, int fd, int i)
{
	char	buff[1];
	char	*str;
	char	*p;
	char	*s;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error("INVALID FILE");
	str = (char *)malloc(sizeof(char) * (1 + i));
	while (1)
	{
		if (read(fd, buff, 1) != 1)
			break ;
		str[i] = buff[0];
		i++;
		str = (char *)realloc(str, sizeof(char) * (1 + i));
	}
	str[i] = '\0';
	p = ft_strrchr(str, '\n');
	s = ft_strndup(p, ft_strlen(str) - (p - str));
	i = 0;
	while (s[++i])
	{
		if (s[i] == COMMENT_CHAR || s[i] == COMMENT_CHAR2)
			break ;
		if (s[i] != COMMENT_CHAR && s[i] != COMMENT_CHAR2 && s[i] != '\t' && s[i] != ' ' && s[i] != '\0')
			error("Perhaps you forgot to end with a newline?");
	}
}

void			open_read(char *av, char ***bot_info)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		error("INVALID FILE");
	while (get_next_line(fd, &(*bot_info)[i]))
	{
		if ((*bot_info)[i][0]) {
			(*bot_info) = (char **) realloc((*bot_info),
											sizeof(char *) * (i + 2));
			i++;
		}
	}
	(*bot_info)[i] = NULL;
	close(fd);
	chek_new_line(av, 0, 0);
}

int				main(int ac, char **av)
{
	char		**bot_info;
	t_corewar	corewar;

	bot_info = (char **)malloc(sizeof(char *));
	bot_info[0] = NULL;
	open_read(av[1], &bot_info);
	corewar.bot.keys = valid(bot_info, &corewar);
	ft_asm(&corewar, ac, av);
	return (0);
}
