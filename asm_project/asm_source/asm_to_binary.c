/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 13:52:41 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/26 13:52:42 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	args_to_bytes(t_command *command, int fd, t_corewar *corewar,
														int current_line)
{
	int		i;
	char	**data;

	i = 0;
	data = (char **)malloc(sizeof(char*) * 4);
	data[2] = NULL;
	data[3] = NULL;
	while (i < command->count_args)
	{
		if (command->arg[i].arg_type == T_REG)
			t_reg_to_byte(command->arg[i].data, fd);
		if (command->arg[i].arg_type == T_DIR)
		{
			data[0] = ft_strdup(command->command_name);
			data[1] = ft_strdup(command->arg[i].data);
			t_dir_to_byte(data, fd, corewar, current_line);
		}
		if (command->arg[i].arg_type == T_IND)
			t_ind_to_byte(command->arg[i].data, fd);
		i++;
	}
}

void	run_throw_command(int fd, t_command *h_command, t_corewar *corewar,
															int *current_line)
{
	while (h_command)
	{
		type_command(corewar->bot, h_command, fd);
		if (h_command->count_args > 1 ||
		!ft_strcmp(h_command->command_name, "aff"))
			get_code_byte(h_command, fd);
		args_to_bytes(h_command, fd, corewar, *current_line);
		h_command = h_command->next;
		(*current_line)++;
	}
}

void	bot_code_to_binary(t_corewar *corewar, int fd, int current_line)
{
	t_command		*command;
	t_hash_table	*hash;
	t_command		*h_command;

	command = corewar->bot.command;
	while (command)
	{
		if (command->method)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys,
			command->method);
			h_command = hash->command;
			run_throw_command(fd, h_command, corewar, &current_line);
		}
		else
		{
			type_command(corewar->bot, command, fd);
			if (command->count_args > 1 ||
			!ft_strcmp(command->command_name, "aff"))
				get_code_byte(command, fd);
			args_to_bytes(command, fd, corewar, current_line);
			current_line++;
		}
		command = command->next;
	}
}

void	ft_asm(t_corewar *corewar)
{
	t_header		*header;
	char			*file_path;
	int				fd;
	unsigned int	magic;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	bzero(header->prog_name, header->prog_size);
	bzero(header->comment, header->prog_size);
	ft_memcpy(header->prog_name, corewar->bot.name,
	ft_strlen(corewar->bot.name));
	ft_memcpy(header->comment, corewar->bot.comment,
	ft_strlen(corewar->bot.comment));
	file_path = ft_strjoin("../", ft_strjoin(header->prog_name, ".cor"));
	fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	magic = reverse_magic(header->magic);
	write(fd, &magic, sizeof(magic) + sizeof(unsigned int) - sizeof(magic));
	write(fd, header->prog_name, (sizeof(*header->prog_name) * PROG_NAME_LENGTH
	+ 1 + sizeof(unsigned int) - sizeof(*header->prog_name)));
	get_prog_size(header, corewar, fd, corewar->bot.command);
	write(fd, header->comment, sizeof(*header->comment) * COMMENT_LENGTH
	+ 1 + sizeof(unsigned int) - sizeof(*header->comment));
	bot_code_to_binary(corewar, fd, 1);
	close(fd);
}
