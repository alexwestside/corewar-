

#include "machine.h"

void	init_vm(t_machine *vm, char **argv)
{
	if (vm->count_players == 0)
		usage(2, argv[1], NULL);
	vm->head_lst = NULL;
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
	vm->flags.number = 0;
    vm->flags.flag = '\0';
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

void	error_exit(char *str, int code, t_machine *vm)
{
	ft_putstr("Error : ");
	if (!ft_strcmp(str, "\0"))
		ft_printf("%s ", strerror(errno));
	else
		ft_putstr(str);
	release_memory(vm);
	exit(code == 0 ? errno : code);
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
		if ((!ft_strcmp(argv[i], "-dump") && i++) || !ft_strcmp(argv[i], "-g")
			|| (!ft_strcmp(argv[i], "-n") && i++))
			continue ;
		fd = open(argv[i], O_RDONLY);
		fd == -1 ? error_exit("\0", 0, NULL) : 0;
		(int)read(fd, 0, 0) == -1 ? error_exit("\0", 0, NULL) : 0;
		*count += fd != -1 ? 1 : 0;
		close(fd);
		if (*count > MAX_PLAYERS)
			error_exit("Too many files", -5, NULL);
		j < MAX_PLAYERS ? paths[j++] = argv[i] : 0;
	}
	paths[i] = NULL;
}
