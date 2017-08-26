/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_command_corewar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:56:26 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:56:28 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

void				lexical_error(char *str, int i)
{
	if (!*str || (i == 1 && !ft_isdigit(*str)) ||
		(i == 2 && !ft_strchr(LABEL_CHARS, *str)))
		error("Lexical error");
}

void				char_error(char *str, int i)
{
	char			*p;

	if (i == 0)
	{
		p = ft_strchr(str, '"');
		if (*(++p))
			error("Syntax error");
	}
	else if (!str || (i == 1 && is_name(str)) || (i == 2 && is_comment(str))
		|| is_method(str))
		error("segmentation fault in origin asm");
}

int					ft_len_two_arr(char **a)
{
	int				i;

	i = 1;
	while (a[i] != NULL && ft_strchr(a[i], SEPARATOR_CHAR))
		i++;
	return (i + 1);
}

void				ft_add_args(char **a, t_command **tmp, int i)
{
	(*tmp)->command_name = ft_strdup(a[0]);
	while (a[++i] != NULL)
	{
		(*tmp)->count_args = ft_len_two_arr(a) - 1;
		if (i == 1)
		{
			(*tmp)->arg[0].data = ft_strndup(a[1], ft_strclen(a[1],
					SEPARATOR_CHAR));
			(*tmp)->arg[0].arg_type = ft_arg_type(a[1]);
		}
		if (i == 2)
		{
			(*tmp)->arg[1].data = ft_strndup(a[2], ft_strclen(a[2],
					SEPARATOR_CHAR));
			(*tmp)->arg[1].arg_type = ft_arg_type(a[2]);
		}
		if (i == 3)
		{
			(*tmp)->arg[2].data = ft_strndup(a[3], ft_strclen(a[3],
					SEPARATOR_CHAR));
			(*tmp)->arg[2].arg_type = ft_arg_type(a[3]);
		}
	}
}

void				ft_add_command(t_command **command, char *name, char **a)
{
	t_command		*tmp;
	t_command		*head;

	tmp = (t_command *)malloc(sizeof(t_command));
	tmp->next = NULL;
	tmp->method = NULL;
	tmp->command_name = NULL;
	if (name != NULL)
		tmp->method = ft_strndup(name, ft_strclen(name, LABEL_CHAR));
	else
		ft_add_args(a, &tmp, 0);
	if (*command == NULL)
		*command = tmp;
	else
	{
		head = *command;
		while ((*command)->next != NULL)
			*command = (*command)->next;
		(*command)->next = tmp;
		*command = head;
	}
}
