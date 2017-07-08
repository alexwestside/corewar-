#include "machine.h"

void	usage(int count, char *s)
{
	if (count == 1)
	{
		ft_putstr("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
		exit(0);
	}
	else if (count == 2)
	{
		ft_putstr("File ");
		ft_putstr(s);
		ft_putendl(" is too small to be a champion");
		exit(0);
	}
	else
		exit(0);
}

int 	is_number(char *s)
{
	int 	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

void	work_with_flags(char **argv, int argc, t_flags *flags)
{
	int 	i;

	i = -1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-d"))
		{
			if (i == 1)
				flags->flag = 'd';
			else
				usage(1, NULL);
		}
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (i != argc - 1 && is_number(argv[i + 1]))
				flags->number = ft_atoi(argv[i + 1]);
			else
				usage(1, NULL);
		}
	}
}
