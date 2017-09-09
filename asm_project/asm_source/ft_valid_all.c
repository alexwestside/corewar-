/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:57:42 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:57:43 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

t_op			*find_t_op(char *str)
{
	int			i;

	i = -1;
	if (str)
	{
		while (++i < 16)
			if (!ft_strcmp(g_op_tab[i].command_name, str))
				return (&g_op_tab[i]);
	}
	return (NULL);
}

void			valid_args(t_op *tmp, t_args *args, int count_args,
					t_hash_key p)
{
	int			i;
	int			j;

	i = -1;
	while (++i < count_args)
	{
		j = -1;
		while (++j < 3)
		{
			if (args[i].arg_type == tmp->args[i][j])
				break ;
			else if (j == 2 && args[i].arg_type != tmp->args[i][j])
				error("Invalid parameter 0 type");
		}
		if (args[i].arg_type == T_DIR)
			check_dir(args[i].data, p.hash_table, p.key);
		else if (args[i].arg_type == T_REG)
			check_reg(args[i].data);
		else if (args[i].arg_type == T_IND)
			check_ind(args[i].data);
	}
}

void			valid_command(t_command *command, t_hash_table **hash_table,
					unsigned int *keys)
{
	t_op		*tmp;
	t_hash_key	p;

	tmp = find_t_op(command->command_name);
	if (tmp == NULL)
	{
		command->count_args > 0 ? check_args(command->arg,
			command->command_name, command->count_args) : 0;
		error("Syntax error");
	}
	else
	{
		if (tmp->count_args != command->count_args)
			error("Invalid parameter");
		p.hash_table = hash_table;
		p.key = keys;
		valid_args(tmp, command->arg, command->count_args, p);
	}
}

void			valid_name_method(char *str)
{
	while (str && *str)
	{
		if (!ft_strchr(LABEL_CHARS, *str))
			error("Lexical error");
		str++;
	}
}
