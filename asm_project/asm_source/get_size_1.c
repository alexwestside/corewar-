/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 13:54:05 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/26 13:54:06 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_prog_size(t_header *header, t_corewar *corewar,
int fd, t_command *command)
{
	t_command		*h_command;

	while (command)
	{
		if (!command->command_name)
		{
			h_command = get_table(corewar->bot.hash_table,
			corewar->bot.keys, command->method, NULL, 0)->command;
			while (h_command)
			{
				if (!h_command->command_name)
					break ;
				gps_1(header, &h_command);
			}
		}
		else
		{
			if (!command->command_name)
				break ;
			gps_2(header, command);
		}
		command = command->next;
	}
	swap_bytes((char *)&header->prog_size, sizeof(header->prog_size));
	write(fd, &header->prog_size, sizeof(header->prog_size));
}

void	gps_2(t_header *header, t_command *command)
{
	header->prog_size++;
	if (command->count_args > 1 && ft_strcmp(command->command_name, "aff"))
		header->prog_size++;
	header->prog_size += get_size_args(command);
}

void	gps_1(t_header *header, t_command **h_command)
{
	header->prog_size++;
	if ((*h_command)->count_args > 1 &&
		ft_strcmp((*h_command)->command_name, "aff"))
		header->prog_size++;
	header->prog_size += get_size_args(*h_command);
	*h_command = (*h_command)->next;
}
