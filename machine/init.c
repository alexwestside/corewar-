

#include "machine.h"

void	init_vm(t_machine *vm, char **argv)
{
	if (vm->count_players == 0)
		usage(2, argv[1], NULL);
	vm->head_lst = NULL;
    vm->cycle = 0;
	vm->count_live = 0;
	vm->iter_cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->iter_max_checks = 0;
	vm->players = create_players(vm->count_players);
	vm->arena = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->color_arena = (unsigned char *)malloc(MEM_SIZE * sizeof(unsigned char));
	if (vm->arena == NULL || vm->color_arena == NULL)
		error_exit("some thing wrong", 999, vm);
    ft_memset(vm->color_arena, un_byte, MEM_SIZE);
	vm->count_forks = 0;
	vm->won_player = 0;
}

t_player	*create_players(int count)
{
	int 	i;
	t_player *players;

	i = -1;
	players = (t_player *)malloc(count * sizeof(t_player));
	while (players && ++i < count)
	{
		players[i].id = 0;
		players[i].last_live = 0;
		players[i].count_live = 0;
		players[i].magic = 0;
		ft_bzero(players[i].prog_name, PROG_NAME_LENGTH);
		players[i].prog_size = 0;
		ft_bzero(players[i].comment, PROG_NAME_LENGTH);
		players[i].code = NULL;
	}
	return (players ? players : NULL);
}

//void	error_exit(char *str, int code, t_machine *vm)
//{
//	ft_putstr("Error : ");
//	if (!ft_strcmp(str, "\0"))
//		ft_printf("%s ", strerror(errno));
//	else
//		ft_putstr(str);
//	release_memory(vm);
//	exit(code == 0 ? errno : code);
//}

void	error_exit(char *str, int code, t_machine *vm)
{
	if (code == -1)
		ft_printf("Can't read source file %s\n", str);
	else if (code == -5)
		ft_printf("ERROR: Too many champions max are %d\n", MAX_PLAYERS);
	else if (code == 1)
		ft_printf("ERROR: %s is too small to be a champion \n", str);
	else if (code == 6)
		ft_printf("ERROR: File %s has a code size that differ from what its header says\n", str);
	release_memory(vm);
	exit(code);
}

/*
** func check_param check argv when user wrote
**  N - number important
**  1 its return argv a | g | dump N | v N
**  2 its return argv n N
**  3 its return all argv doesnt have first char is '-'
*/

int		check_param(int num_strs, char **strs, int *i)
{
	if (strs[*i][0] == '-')
	{
		if (!ft_strcmp(strs[*i], "-a") || !ft_strcmp(strs[*i], "-g"))
			return (1);
		else if (!ft_strcmp(strs[*i], "-dump") || !ft_strcmp(strs[*i], "-v"))
		{
			if (*i + 1 < num_strs && is_number(strs[++(*i)]))
				return (1);
			else
				print_usage();
		}
		else if (!ft_strcmp(strs[*i], "-n"))
		{
			if (*i + 1 < num_strs && is_number(strs[++(*i)]))
				return (2);
			else
				print_usage();
		}
		else
			print_usage();
	}
	return (3);
}

void	fast_check_position_args(int num, char **strs)
{
	int i;
	int f;
	int res;

	i = 0;
	f = 0;
	while (++i < num)
	{
		res = check_param(num, strs, &i);
		if (res == 1 && f)
			print_usage();
		else if (res == 1 && f == 0)
			f = 1;
	}
}

void 	create_point_path(int argc, char **argv, char *paths[MAX_PLAYERS],
						  unsigned *count)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	*count = 0;
	ft_bzero(paths, MAX_PLAYERS * sizeof(char *));
	while (++i < argc)
	{
		if (check_param(argc, argv, &i) != 3)
			continue ;
		fd = open(argv[i], O_RDONLY);
		fd == -1 ? error_exit(argv[i], -1, NULL) : 0;
		(int)read(fd, 0, 0) == -1 ? error_exit(argv[i], -1, NULL) : 0;
		*count += fd != -1 ? 1 : 0;
		close(fd);
		if (*count > MAX_PLAYERS)
			error_exit("\0", -5, NULL);
		j < MAX_PLAYERS ? paths[j++] = argv[i] : 0;
	}
	paths[i] = NULL;
}
