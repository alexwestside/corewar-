#include "corewar.h"

void		valid(char **text, t_corewar *corewar)
{
	char 	*name;
	char 	*comment;

	ft_name_comment(&name, &comment, &text);
	corewar->bot = ft_command(text);
	corewar->bot.name = name;
	corewar->bot.comment = comment;
}

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


int 		main(int ac, char **av)
{
	char 	**text;
	t_corewar	corewar;

	text = open_read(av[1]);
	valid(text, &corewar);
	_asm(corewar);
}