
#include "machine.h"

void	usage(int count, char *s, t_machine *vm)
{
	if (count == 1)
		ft_putstr("Usage: ./corewar [-g] [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	else if (count == 2)
	{
		ft_putstr("File ");
		ft_putstr(s);
		ft_putendl(" is too small to be a champion");
	}
	release_memory(vm);
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

//int 	get_number(int argc, char **argv, int i)
//{
//	if (i < argc && is_number(argv[i]))
//		return (ft_atoi(argv[i]));
//	usage(1, NULL);
//	return (0);
//}

void	copy_flags(char **argv, int argc, int i, t_machine *vm)
{
	char *tmp;

	tmp = argv[i];
	vm->flags.flag = *(tmp + 1);
	if (!ft_strcmp(argv[i], "-g"))
		return ;
	if (i + 1 < argc && is_number(argv[i + 1]))
		vm->flags.number = ft_atoi(argv[i + 1]);
	else
		usage(1, NULL, vm);
}

void	work_with_flags(char **argv, int argc, t_machine *vm)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-g"))
		{
			if (i == 1)
				copy_flags(argv, argc, i, vm);
			else
				usage(1, NULL, vm);
		}
		else if (!ft_strcmp(argv[i], "-n"))
		{
			if (i + 1 < argc && is_number(argv[i + 1]))
				continue ;
			else
				usage(1, NULL, vm);
		}
}
