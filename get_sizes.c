
#include "asm.h"

size_t	get_t_dir_size(char *command_name)
{
	size_t	size;
	int		i;

	i = -1;
	while (++i < REG_NUMBER) {
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break;
	}
	size = op_tab[i].cod_octal ? 2 : 4;
	return (size);
}

int	get_size_args(t_command *command) {
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (++i < command->count_args) {
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

size_t	get_distance_to_method(char *command_name, t_corewar *corewar, int current_line)
{
	size_t			distance;
	t_command		*command;
	t_hash_table	*hash;
	t_command		*hash_command;

	distance = 0;
	command = corewar->bot.command;
	while (command)
	{
		if (command->method) {
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			hash_command = hash->command;
			while (hash_command)
			{
				if (!ft_strcmp(command_name, hash->lable))
					return (distance);
				distance += 1;
				if (hash_command->count_args > 1 || !ft_strcmp(hash_command->command_name, "aff"))
					distance += 1;
				distance += get_size_args(hash_command);
				hash_command = hash_command->next;
			}
			if (!ft_strcmp(command_name, hash->lable))
				return (distance);
		}
		else
		{
			distance += 1;
			if (command->count_args > 1 || !ft_strcmp(command->command_name, "aff"))
				distance += 1;
			distance += get_size_args(command);
		}
		command = command->next;
	}
	return (distance);
}

void get_prog_size(header_t *header, t_corewar *corewar, int fd) {
	unsigned		size;
	t_command		*command;
	t_hash_table	*hash;
	t_command		*_command;

	size = 0;
	command = corewar->bot.command;
	while (command) {
		if (!command->command_name) {
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			_command = hash->command;
			while (_command) {
				if (!_command->command_name)
					break;
				size++;
				if (_command->count_args > 1 && ft_strcmp(_command->command_name, "aff"))
					size++;
				size += get_size_args(_command);
				_command = _command->next;
			}
		}
		else {
			if (!command->command_name)
				break;
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