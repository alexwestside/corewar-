

#include "machine.h"

int 	create_point_path(int argc, char **argv, char **paths)
{
	int			i;
	int			fd;
	int 		err;
	unsigned	count;

	i = -1;
	err = 0;
	count = 0;
	if (paths == NULL || argc == 0 || argv == NULL)
		return (0);
	while (++i < argc && count <= MAX_ARGS_NUMBER)
	{
		fd = open(argv[i], O_RDONLY);
		fd != -1 && (err = (int)read(fd, 0, 0)) == -1 ? perror("Error ") : 0;
		count += fd != -1 ? 1 : 0;
		if (count > MAX_ARGS_NUMBER || err == -1)
			break ;
		paths[i] = argv[i];
		close(fd);
	}
	paths[i] = NULL;
	return (count <= MAX_PLAYERS && err == 0 ? count : 0);
}