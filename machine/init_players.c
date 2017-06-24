
#include "machine.h"

header_t	*create_players(int count)
{
	header_t *players;

	players = (header_t *)malloc(count * sizeof(header_t));
	return (players ? players : NULL);
}

char 	**create_code_player(int count)
{
	int i;
	char **str;

	i = -1;
	*str = (char *)malloc((count + 1) * sizeof(char*));
	if (*str == NULL)
		return (NULL);
	while (++i <= count)
		str[i] = NULL;
//		if ((str[i] = ft_strnew(count)) == NULL)
//			return (NULL);
//	str[i] = NULL;
	return (str);
}