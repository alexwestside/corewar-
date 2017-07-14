
#include "asm.h"

size_t get_t_dir_size(char *command_name)
{
	size_t size = 0;
	int i = -1;

	while (++i < REG_NUMBER)
	{
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break;
		i++;
	}
	size = op_tab[i].cod_octal? 2 : 4;
//	return (op_tab[i].cod_octal ? 4 : 2);
	return (size);
}

int get_size_args(t_command *command)
{
	int size = 0;
	int i = -1;

	while (++i < command->count_args)
	{
		if (command->arg[i].arg_type == T_DIR)
		{
			size += get_t_dir_size(command->command_name);
//			if (!ft_strchr(command->arg[i].data, LABEL_CHAR))
//				size += 2;
		}
		if (command->arg[i].arg_type == T_IND)
			size += 2;
		if (command->arg[i].arg_type == T_REG)
			size += 1;
	}
	return (size);
}

size_t get_distance_to_method(char *command_name, /*t_hash_table *hash, */t_corewar * corewar)
{
	size_t distance = 0;
	t_command *command;
	t_hash_table *hash;
	t_command *hash_command;

	command = corewar->bot.command;
	while (command)
	{
		if (command_name && !ft_strcmp(command->method, command_name))
			break ;
		if (!command->command_name)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			hash_command = hash->command;
			while (hash_command)
			{
				if(!strcmp(hash_command->command_name, command_name))
					return (distance);
//				distance += !ft_strcmp(hash_command->command_name, "aff") ? 1 : 2;
				if (hash_command->count_args > 1 || !ft_strcmp(hash_command->command_name, "aff"))
					distance += 2;
				else
					distance += 1;
				distance += get_size_args(hash_command);
				hash_command = hash_command->next;
			}
		}
		command = command->next;
	}
	return (distance);
}

void get_prog_size(header_t *header, t_corewar *corewar, int fd)
{
	unsigned size = 0;
	t_command *command;
	t_hash_table *hash;
	t_command *_command;

	command = corewar->bot.command;
	while (command)
	{
		if (!command->command_name)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			_command = hash->command;
			while (_command)
			{
				if (!_command->command_name)
					break ;
				size++;
				if (_command->count_args > 1 && ft_strcmp(_command->command_name, "aff"))
					size++;
				size += get_size_args(_command);
				_command = _command->next;
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
//		if (!command->method)
//			_command = command;
//		else
//		{
//			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
//			_command = hash->command;
//		}
//		while (_command)
//		{
//			if (!_command->command_name)
//				break ;
//			size++;
//			if (_command->count_args > 1 && ft_strcmp(_command->command_name, "aff"))
//				size++;
//			size += get_size_args(_command);
//			_command = _command->next;
//		}
		command = command->next;
	}
	header->prog_size = size;
	write(fd, "\0", sizeof(header->prog_size) - ((size / (MEM_SIZE >> 4)) + 1));
	swap_bytes((char*)&header->prog_size, sizeof(header->prog_size));
	write(fd, &header->prog_size, (size / (MEM_SIZE >> 4)) + 1);
//	swap_bytes((char*)&header->prog_size, sizeof(header->prog_size));
//	write(fd, &header->prog_size, sizeof(header->prog_size));
}

//unsigned int swap_bytes(unsigned int n)
//{
//	unsigned int b2 = (0x0000FF00 & n);
//	unsigned int b4 = (0xFF000000 & n);
//	n ^= b2 | b4;                 // Clear the second and fourth bytes
//	n |= (b2 << 16) | (b4 >> 16); // Swap and write them.
//	return n;
//}


void get_zjmp_distance(char *command_name, char *command_data, int fd, t_corewar *corewar)
{
	size_t dist_to_zjmp = 0;
	size_t dist_to_method = 0;
	int zjmp_distance = 0;

	size_t size = get_t_dir_size(command_name);
	dist_to_zjmp = get_distance_to_method(command_name, corewar);
	dist_to_method = get_distance_to_method(ft_strsplit(command_data, ':')[1], corewar);
	zjmp_distance = (int)(dist_to_method - dist_to_zjmp);
	swap_bytes((char *)&zjmp_distance, size);
	write(fd, &zjmp_distance, size);
}