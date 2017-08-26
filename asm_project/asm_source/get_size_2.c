/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 13:54:15 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/26 13:54:15 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	get_distance_to_command(t_corewar *corewar, int current_line,
size_t distance, t_command *command)
{
	t_command		*hash_command;

	while (command)
	{
		if (command->method)
		{
			hash_command = get_table(corewar->bot.hash_table,
corewar->bot.keys, command->method)->command;
			while (hash_command)
			{
				if (!(current_line - 1) || !current_line)
					return (distance);
				gdtc_1(&current_line, &distance, &hash_command);
			}
		}
		else
		{
			if (!(current_line - 1) || !current_line)
				return (distance);
			gdtc_2(command, &current_line, &distance);
		}
		command = command->next;
	}
	return (distance);
}

void	gdtc_2(t_command *command, int *current_line, size_t *distance)
{
	(*distance) += 1;
	if (command->count_args > 1 || !ft_strcmp(command->command_name, "aff"))
		(*distance) += 1;
	(*distance) += get_size_args(command);
	(*current_line)--;
}

void	gdtc_1(int *current_line, size_t *distance, t_command **hash_command)
{
	(*distance) += 1;
	if ((*hash_command)->count_args > 1 ||
		!ft_strcmp((*hash_command)->command_name, "aff"))
		(*distance) += 1;
	(*distance) += get_size_args((*hash_command));
	(*hash_command) = (*hash_command)->next;
	(*current_line)--;
}
