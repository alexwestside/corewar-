
#include "asm.h"

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

