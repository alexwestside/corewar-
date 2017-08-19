
#include "machine.h"


void		print_usage(void)
{
	ft_putendl("Usage: ./corewar [-dump nbr_cycles | -v N | -a | -g] [[-n number] champion1.cor] ...");
	ft_putendl("    -a        : Prints output from \"aff\" (Default is to hide it)");
	ft_putendl("    -n N      : sets the number of the player. If non-existent, the player will have the next"
					   "\n\t\tavailable number in the order of the parameters (Default start: -1). If there"
					   "\n\t\tis a given N or whether the number is zero, the player will be given the smallest\n\t\tnegative number from the existing players");
	ft_putendl("#### TEXT OUTPUT MODE ##############################################################################");
	ft_putendl("    -dump N   : Dumps memory after N cycles then exits");
	ft_putendl("    -v N      : Verbosity levels, can be added together to enable several");
	ft_putendl("                - 0 : Show only essentials");
	ft_putendl("                - 1 : Show lives");
	ft_putendl("                - 2 : Show cycles");
	ft_putendl("#### NCURSES OUTPUT MODE ###########################################################################");
	ft_putendl("    -g        : Ncurses output mode");
	ft_putendl("####################################################################################################");
	exit(0);
}

void	usage(int count, char *s, t_machine *vm)
{
	if (count == 1)
		print_usage();
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

void	copy_flags(char **argv, int argc, int i, t_flags *flags)
{
	char *tmp;

	tmp = argv[i];
	flags->flag = *(tmp + 1);
	if (!ft_strcmp(argv[i], "-g") || !ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-a"))
		return ;
	if (i + 1 < argc && is_number(argv[i + 1]))
		flags->number = ft_atoi(argv[i + 1]);
	else
		print_usage();
}

t_flags		work_with_flags(int argc, char **argv)
{
	int	i;
	t_flags flags;

	i = 0;
	ft_memset(&flags, 0, sizeof(flags));
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-g") ||
				!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-a"))
			i == 1 ? copy_flags(argv, argc, i, &flags) : print_usage();
		else if (!ft_strcmp(argv[i], "-n"))
		{
			if (i + 1 < argc && is_number(argv[i + 1]))
				continue ;
			else
				print_usage();
		}
	return (flags);
}
