
#include "corewar.h"

#define HEX_BASE "0123456789abcdef"

void hex(int n, int fd)
{
	if (n >= 16)
	{
		hex(n / 16, fd);
		hex(n % 16, fd);
	}
	else
		ft_putchar_fd(HEX_BASE[n], fd);
}

void hex_magic(int n, int fd, char *str, size_t *i)
{
	if (n >= 16)
	{
		hex_magic(n / 16, fd, str, i);
		hex_magic(n % 16, fd, str, i);
	}
	else
	{
		str[*i] = HEX_BASE[n];
		(*i)++;
		str = realloc(str, *i + 1);
	}
}

void str_to_hex(char *str, int fd, int len)
{


	while (len--)
	{
//		if (*str)
//		{
		hex(*str, fd);
		str++;
//		}
//		else
//			ft_putstr_fd("00", fd);
	}
}

void print_hex_magic(char *str, int fd)
{
	int i = 0;
	char *p = str;

	while (*str)
	{
		if (ft_strlen(p) + i < 8)
		{
			ft_putchar_fd(0, fd);
			i++;
		}
		else
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}

unsigned int reverse_magic(unsigned int magic)
{
	unsigned int res = 0;
	unsigned int i = 0;

	while (i < 4)
	{
		const unsigned int byte = (magic >> 8 * i) & 0xff;
		res |= byte << (24 - 8 * i);
		i++;
	}
	return res;
}



int ft_isdigit_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int binary_type_args(int i, int arg)
{
	int res;

	res = 0;
	if (arg == T_REG)
		res = REG_CODE << (6 - (i != 2 ? i * 2 : 4));
	if (arg == T_DIR)
		res = DIR_CODE << (6 - (i != 2 ? i * 2 : 4));;
	if (arg == T_IND)
		res = IND_CODE << (6 - (i != 2 ? i * 2 : 4));;
	return (res);
}

int count_arg(t_command *_command)
{
	int count_arg = 0;

	_command->arg[0].data ? count_arg += 1 : 0;
	_command->arg[1].data ? count_arg += 1 : 0;
	_command->arg[2].data ? count_arg += 1 : 0;
	return (count_arg);
}

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

int get_code_byte(t_command *_command)
{
	int code_byte;
	int i;
	int arg;

	i = -1;
	code_byte = 0;
	arg = count_arg(_command);
	while (++i < MAX_ARGS_NUMBER)
	{
		if (_command->arg[i].arg_type == T_REG)
			code_byte += REG_CODE << (6 - (i != 2 ? i * 2 : 4));
		if (_command->arg[i].arg_type == T_DIR)
			code_byte += DIR_CODE << (6 - (i != 2 ? i * 2 : 4));;
		if (_command->arg[i].arg_type == T_IND)
			code_byte += IND_CODE << (6 - (i != 2 ? i * 2 : 4));;
	}
	return (code_byte);
}

void bot_code_to_binary(t_corewar *corewar, int fd)
{
	t_command *command;
	t_hash_table *hash;
	t_command *_command;

	command = corewar->bot.command;
	int arg;
	int code_byte;

	while (command)
	{
		hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
		_command = hash->command;
		while (_command)
		{
			type_command(corewar->bot, _command, fd);
			arg = count_arg(_command);
			code_byte = 0;
			if (arg > 1 || !ft_strcmp(_command->command_name, "aff"))
			{
				code_byte = get_code_byte(_command);
				write(fd, &code_byte, sizeof(char));
			}
			_command = _command->next;
		}
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

	unsigned int magic = reverse_magic(COREWAR_EXEC_MAGIC);
	write(fd, &magic, sizeof(magic) + sizeof(unsigned int) - sizeof(magic));
	write(fd, header->prog_name,
		  (sizeof(*header->prog_name) * (PROG_NAME_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->prog_name))));
	write(fd, &header->prog_size, (sizeof(header->prog_size) + sizeof(unsigned int) - sizeof(header->prog_size)));
	write(fd, header->comment,
		  sizeof(*header->comment) * COMMENT_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->comment));

	bot_code_to_binary(corewar, fd);
	close(fd);

}

void _asm(t_corewar corewar)
{

//	char *s = malloc(0);
//	t_corewar *corewar;
//
//	init_corewar(&corewar);
//	read_bot_info(corewar->bot);
//	valid_bot(bot);

	asm_to_binary(&corewar);

//	init_hash(&corewar);
//	make_asm(&bot);

}
