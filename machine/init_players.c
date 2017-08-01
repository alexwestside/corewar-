
#include "machine.h"

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

unsigned char 	**create_code_player(int count)
{
	int i;
	unsigned char **str;

	i = -1;
	str = (unsigned char **)malloc((count + 1) * sizeof(unsigned char*));
	if (*str == NULL)
		return (NULL);
//	while (++i <= count)
//		str[i] = NULL;
//		if ((str[i] = ft_strnew(count)) == NULL)
//			return (NULL);
//	str[i] = NULL;
	return (str);
}