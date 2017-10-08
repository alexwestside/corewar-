/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 13:54:22 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/26 13:54:22 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	get_t_dir_size(char *command_name)
{
	size_t	size;
	int		i;

	i = -1;
	while (++i < REG_NUMBER)
		if (!ft_strcmp(command_name, g_op_tab[i].command_name))
			break ;
	size = g_op_tab[i].cod_octal ? 2 : 4;
	return (size);
}

int		get_size_args(t_command *command)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (++i < command->count_args)
	{
		if (command->arg[i].arg_type == T_DIR)
			size += get_t_dir_size(command->command_name);
		if (command->arg[i].arg_type == T_IND)
			size += 2;
		if (command->arg[i].arg_type == T_REG)
			size += 1;
	}
	return (size);
}

void	get_distance_to_method_1(size_t *distance, t_command *command)
{
	(*distance) += 1;
	if (command->count_args > 1 || !ft_strcmp(command->command_name, "aff"))
		(*distance) += 1;
	(*distance) += get_size_args(command);
}

void	get_distance_to_method_2(size_t *distance, t_command **hash_command)
{
	(*distance) += 1;
	if ((*hash_command)->count_args > 1 ||
!ft_strcmp((*hash_command)->command_name, "aff"))
		(*distance) += 1;
	(*distance) += get_size_args((*hash_command));
	(*hash_command) = (*hash_command)->next;
}

size_t	get_distance_to_method(char *command_name, t_corewar *corewar,
									size_t distance, t_command *hash_command)
{
	t_command		*command;
	t_hash_table	*hash;

	command = corewar->bot.command;
	while (command)
	{
		if (command->method)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys,
			command->method, NULL, 0);
			hash_command = hash->command;
			while (hash_command)
			{
				if (!ft_strcmp(command_name, hash->lable))
					return (distance);
				get_distance_to_method_2(&distance, &hash_command);
			}
			if (!ft_strcmp(command_name, hash->lable))
				return (distance);
		}
		else
			get_distance_to_method_1(&distance, command);
		command = command->next;
	}
	return (distance);
}
