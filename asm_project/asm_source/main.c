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


void open_read(char *av, char ***text)
{
	int		fd;
	int 	i;
	char **a;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("INVALID FILE");
		exit(0);
	}
	while (get_next_line(fd, &(*text)[i]))
	{
		if ((*text)[i][0]) {
			(*text) = (char **) realloc((*text), sizeof(char *) * (i + 2));
			i++;
		}
	}
	(*text)[i] = NULL;
	if (!ft_strchr((*text)[i - 1], '\n'))
	{
		a = ft_strsplit_2args((*text)[i-1], ' ', '\t');
		if (a[0] && *(a[0]) != COMMENT_CHAR && *(a[0]) != COMMENT_CHAR2)
			error("!!!");
	}
}

int		main(int ac, char **av)
{
	char		**text;
	t_corewar	corewar;

	(void)ac;
	text = (char **)malloc(sizeof(char *));
	text[0] = NULL;
	open_read(av[1], &text);
	corewar.bot.keys = valid(text, &corewar);
	ft_asm(&corewar);
}

//while (get_next_line(fd, &(bot)->info[i]))
//{
//if ((bot)->info[i][0])
//{
//(bot)->info = (char **) realloc((bot)->info, sizeof(char *) * (i + 2));
//i++;
//}
//}
//(bot)->info[i] = NULL;
