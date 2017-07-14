
#include "asm.h"

void type_command(t_bot bot, t_command *command, int fd)
{
	int i = 0;
	char *command_name;

	if (!command->command_name)
		command_name = get_command_name(bot.hash_table, bot.keys, command->method);
	else
		command_name = command->command_name;
	while (i < REG_NUMBER)
	{
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break;
		i++;
	}
	write(fd, &op_tab[i].opcode, sizeof(char));
}

void get_code_byte(t_command *_command, int fd)
{
	int code_byte;
	int i;
	int arg;

	i = -1;
	code_byte = 0;
//	arg = count_arg(_command);
	while (++i < _command->count_args)
	{
		if (_command->arg[i].arg_type == T_REG)
			code_byte += REG_CODE << (6 - (i != 2 ? i * 2 : 4));
		if (_command->arg[i].arg_type == T_DIR)
			code_byte += DIR_CODE << (6 - (i != 2 ? i * 2 : 4));;
		if (_command->arg[i].arg_type == T_IND)
			code_byte += IND_CODE << (6 - (i != 2 ? i * 2 : 4));;
	}
	write(fd, &code_byte, sizeof(char));
//	return (code_byte);
}

void t_IND_to_byte(char *command_name, char *command_data, int fd)
{
	size_t size = 2;
	int num = ft_atoi(command_data);
	swap_bytes((char *)&num, 2);
	write(fd, &num, size);
}

void t_DIR_to_byte(char *command_name, char *command_data, int fd, t_hash_table *hash, t_corewar *corewar)
{
	size_t size = get_t_dir_size(command_name);
	char *t_dir = NULL;
	size_t distance = 0;
	int i = -1;

	while (++i < REG_NUMBER)
	{
		if (!ft_strcmp(command_name, "zjmp"))
			return (get_zjmp_distance(command_name, command_data, fd, corewar));
		if (ft_strstr(command_data, op_tab[i].command_name))
		{
			t_dir = op_tab[i].command_name;
			distance = get_distance_to_method(t_dir, /*hash, */corewar);
			write(fd, "\0", size - ((size / (MEM_SIZE >> 4)) + 1));
			write(fd, &distance, (size / (MEM_SIZE >> 4)) + 1);
			return ;
		}
	}
	int dir_num = ft_atoi(ft_strsplit(command_data, '%')[0]);
	write(fd, "\0", size - ((size / (MEM_SIZE >> 4)) + 1));
	write(fd, &dir_num, (size / (MEM_SIZE >> 4)) + 1);
}

void t_REG_to_byte(char *command_name, char *command_data, int fd)
{
	size_t size = 1;
	int num_reg = ft_atoi(ft_strsplit(command_data, 'r')[0]);
	write(fd, &num_reg, size);
}

void args_to_bytes(t_command *command, int fd, t_hash_table *hash, t_corewar *corewar)
{
	int i = 0;

	while (i < command->count_args)
	{
		if (command->arg[i].arg_type == T_REG)
			t_REG_to_byte(command->command_name, command->arg[i].data, fd);
		if (command->arg[i].arg_type == T_DIR)
			t_DIR_to_byte(command->command_name, command->arg[i].data, fd, hash, corewar);
		if (command->arg[i].arg_type == T_IND)
			t_IND_to_byte(command->command_name, command->arg[i].data, fd);
		i++;
	}
}

void bot_code_to_binary(t_corewar *corewar, int fd)
{
	t_command *command;
	t_hash_table *hash;
	t_command *_command;
//	int i = 0;

	command = corewar->bot.command;
//	int arg;

	while (command)
	{
		if (command->method)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			_command = hash->command;
			while (_command)
			{
//				if (!_command->command_name)
//					break ;
				type_command(corewar->bot, _command, fd);
//			arg = count_arg(_command);
				if (_command->count_args > 1 || !ft_strcmp(_command->command_name, "aff"))
					get_code_byte(_command, fd);
				args_to_bytes(_command, fd, hash, corewar);
				_command = _command->next;
//				i++;
			}
		}
		else
		{
			type_command(corewar->bot, command, fd);
//			arg = count_arg(_command);
			if (command->count_args > 1 || !ft_strcmp(command->command_name, "aff"))
				get_code_byte(command, fd);
			args_to_bytes(command, fd, NULL, corewar);
//			i++;
		}
//		if (i == 42)
//			write(1, "1", 1);
//		hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
//		_command = hash->command;
//		while (_command)
//		{
//			type_command(corewar->bot, _command, fd);
////			arg = count_arg(_command);
//			if (_command->count_args > 1 || !ft_strcmp(_command->command_name, "aff"))
//				get_code_byte(_command, fd);
//			args_to_bytes(_command, fd, hash, corewar);
//			_command = _command->next;
//		}
		command = command->next;
	}
}

void asm_to_binary(t_corewar *corewar)
{
	header_t *header = (header_t *) malloc(sizeof(header_t));
	header->magic = COREWAR_EXEC_MAGIC;
	bzero(header->prog_name, header->prog_size);
	bzero(header->comment, header->prog_size);

	ft_memcpy(header->prog_name, corewar->bot.name, ft_strlen(corewar->bot.name));
	ft_memcpy(header->comment, corewar->bot.comment, ft_strlen(corewar->bot.comment));

	char *file_path = ft_strjoin("../", ft_strjoin(header->prog_name, ".cor"));
	int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	unsigned int magic = reverse_magic(header->magic);
	write(fd, &magic, sizeof(magic) + sizeof(unsigned int) - sizeof(magic));
	write(fd, header->prog_name, (sizeof(*header->prog_name) * PROG_NAME_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->prog_name)));
	get_prog_size(header, corewar, fd);
	write(fd, header->comment, sizeof(*header->comment) * COMMENT_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->comment));

	bot_code_to_binary(corewar, fd);
	close(fd);

}

void _asm(t_corewar corewar)
{

	asm_to_binary(&corewar);

}
