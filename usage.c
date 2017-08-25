#include "asm.h"

void			hex(int n, int fd)
{
	if (n >= 16)
	{
		hex(n / 16, fd);
		hex(n % 16, fd);
	}
	else
		ft_putchar_fd(HEX_BASE[n], fd);
}

void			hex_magic(int n, int fd, char *str, size_t *i)
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
	}
}

unsigned int	reverse_magic(unsigned int magic)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (i < 4)
	{
		const unsigned int byte = (magic >> 8 * i) & 0xff;
		res |= byte << (24 - 8 * i);
		i++;
	}
	return (res);
}

int				swap_bytes(char *s, size_t size)
{
	int		i;
	int		j;
	char	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < (size - i) - 1)
		{
			tmp = s[j];
			s[j] = s[j + 1];
			s[j + 1] = tmp;
		}
	}
	return ((int)s);
}

void		error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
