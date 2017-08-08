

#include "machine.h"

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
