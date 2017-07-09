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