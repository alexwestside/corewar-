
#include "op.h"
#include "corewar.h"

size_t	two_dem_strlen(char **s)
{
	char	**p;

	p = s;
	while (*p)
		p++;
	return ((p - s) + 1);
}


void init_bot(t_bot **bot)
{
	(*bot) = (t_bot*)malloc(sizeof(t_bot));
	(*bot)->info = (char **)malloc(sizeof(char *)/* * 2*/);
	(*bot)->info[0] = NULL;
//	(*bot)->info[0] = NULL;
//	(*bot)->info[1] = NULL;
}

void read_bot_info(t_bot **bot)
{
	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/corewar/resources/corewar/champs/examples/zork.s", O_RDONLY);
	size_t i = 0;

	while (get_next_line(fd, &(*bot)->info[i]))
	{
		if ((*bot)->info[i][0])
		{
//			(*bot)->info = ft_realloc(&(*bot)->info, two_dem_strlen((*bot)->info));
			(*bot)->info = (char **)realloc((*bot)->info, sizeof(char *) * (i + 2));
			i++;
		}
	}
	(*bot)->info[i] = NULL;
}

void valid_bot(t_bot *bot)
{



}

int main(void)
{
	t_bot *bot;

	init_bot(&bot);
	read_bot_info(&bot);
	valid_bot(bot);


}
