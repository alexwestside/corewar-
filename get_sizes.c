
#include "asm.h"

size_t	get_t_dir_size(char *command_name)
{
	size_t	size;
	int		i;

	i = -1;
	while (++i < REG_NUMBER)
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break ;
	size = op_tab[i].cod_octal ? 2 : 4;
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

size_t	get_distance_to_command(t_corewar *corewar, int current_line)
{
	size_t			distance;
	t_command		*command;
	t_hash_table	*hash;
	t_command		*hash_command;

	distance = 0;
	command = corewar->bot.command;
	while (command)
	{
		if (command->method)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			hash_command = hash->command;
			while (hash_command)
			{
				if (!(current_line - 1) || !current_line)
					return (distance);
				distance += 1;
				if (hash_command->count_args > 1 || !ft_strcmp(hash_command->command_name, "aff"))
					distance += 1;
				distance += get_size_args(hash_command);
				hash_command = hash_command->next;
				current_line--;
			}
		}
		else
		{
			if (!(current_line - 1) || !current_line)
				return (distance);
			distance += 1;
			if (command->count_args > 1 || !ft_strcmp(command->command_name, "aff"))
				distance += 1;
			distance += get_size_args(command);
			current_line--;
		}
		command = command->next;
	}
	return (distance);
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
	if ((*hash_command)->count_args > 1 || !ft_strcmp((*hash_command)->command_name, "aff"))
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
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
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

void	get_prog_size(header_t *header, t_corewar *corewar, int fd)
{
	unsigned		size;
	t_command		*command;
	t_hash_table	*hash;
	t_command		*h_command;

	size = 0;
	command = corewar->bot.command;
	while (command)
	{
		if (!command->command_name)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			h_command = hash->command;
			while (h_command)
			{
				if (!h_command->command_name)
					break ;
				size++;
				if (h_command->count_args > 1 && ft_strcmp(h_command->command_name, "aff"))
					size++;
				size += get_size_args(h_command);
				h_command = h_command->next;
			}
		}
		else
		{
			if (!command->command_name)
				break ;
			size++;
			if (command->count_args > 1 && ft_strcmp(command->command_name, "aff"))
				size++;
			size += get_size_args(command);
		}
		command = command->next;
	}
	header->prog_size = size;
	swap_bytes((char *)&header->prog_size, sizeof(header->prog_size));
	write(fd, &header->prog_size, sizeof(header->prog_size));
}
