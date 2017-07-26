#include "corewar_valid.h"

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
//    char * fp = "../resources/corewar/champs/examples/zork.s";
//    char * fp = "../resources/corewar/champs/examples/bigzork.s";
//    char * fp = "../resources/corewar/champs/examples/bee_gees.s";
//    char * fp = "../resources/corewar/champs/examples/fluttershy.s";
    char * fp = "../resources/corewar/champs/examples/helltrain.s";
//    char * fp = "../resources/corewar/champs/examples/turtle.s";

	text = open_read(/*av[1]*/fp);
	valid(text, &corewar);
	_asm(corewar);
}