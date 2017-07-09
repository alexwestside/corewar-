#include "corewar.h"

char		**open_read(char *av)
{
	int 	fd;
	char 	*str;
	char 	*s;

	fd = open(av, O_RDONLY);
	s = "";
	while (get_next_line(fd, &str) != 0)
	{
		s = ft_strjoin(s, str);
		s = ft_strjoin(s, "\n");
	}
	return (ft_strsplit(s, '\n'));
}

