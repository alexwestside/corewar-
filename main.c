
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

void init_corewar(t_corewar **corewar)
{
	*corewar = (t_corewar *)malloc(sizeof(t_corewar));
	(*corewar)->bot = (t_bot*)malloc(sizeof(t_bot));
	(*corewar)->bot->info = (char **)malloc(sizeof(char *));
	(*corewar)->bot->info[0] = NULL;
	(*corewar)->table = (char *)malloc(sizeof(char) * 4096);
	(*corewar)->bot->hash_table = (t_hash_table **)malloc(sizeof())
}

void read_bot_info(t_bot **bot)
{
	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/corewar/resources/corewar/champs/examples/zork.s", O_RDONLY);
	size_t i = 0;

	while (get_next_line(fd, &(*bot)->info[i]))
	{
		if ((*bot)->info[i][0])
		{
			(*bot)->info = (char **)realloc((*bot)->info, sizeof(char *) * (i + 2));
			i++;
		}
	}
	(*bot)->info[i] = NULL;
}

void init_hash(t_corewar **corewar)
{




}


int main(void)
{
	t_corewar *corewar;

	init_corewar(&corewar);
	read_bot_info(&corewar->bot);
//	valid_bot(bot);
	init_hash(&corewar);
//	make_asm(&bot);
}
