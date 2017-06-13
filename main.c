
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
	ft_bzero(&(*corewar)->registrs, sizeof(int) * 16);
	(*corewar)->bot = (t_bot*)malloc(sizeof(t_bot));
	(*corewar)->bot->info = (char **)malloc(sizeof(char *));
	(*corewar)->bot->info[0] = NULL;
	(*corewar)->table = (char *)malloc(sizeof(char) * 4096);
	(*corewar)->bot->hash_table = (t_hash_table **)malloc(sizeof(t_hash_table*) * 2);
	(*corewar)->bot->hash_table[0] = (t_hash_table *)malloc(sizeof(t_hash_table));
	(*corewar)->bot->hash_table[0]->method = (t_method *)malloc(sizeof(t_method));
	(*corewar)->bot->hash_table[0]->method->comand = (t_comand *)malloc(sizeof(t_comand));
	(*corewar)->bot->hash_table[0]->method->comand->args = (t_args *)malloc(sizeof(t_args));
	(*corewar)->bot->hash_table[1] = (t_hash_table *)malloc(sizeof(t_hash_table));
	(*corewar)->bot->hash_table[1]->method = (t_method *)malloc(sizeof(t_method));
	(*corewar)->bot->hash_table[1]->method->comand = (t_comand *)malloc(sizeof(t_comand));
	(*corewar)->bot->hash_table[1]->method->comand->args = (t_args *)malloc(sizeof(t_args));
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
	(*corewar)->bot->name = ft_strdup((ft_strsplit((*corewar)->bot->info[0], ' '))[1]);
	(*corewar)->bot->comment = ft_strjoin(ft_strdup((ft_strsplit((*corewar)->bot->info[1], ' '))[1]), ft_strdup((ft_strsplit((*corewar)->bot->info[1], ' '))[2]));
	(*corewar)->bot->hash_table[0]->method->method_name = ft_strdup((ft_strsplit((*corewar)->bot->info[2], '\t'))[0]);
	(*corewar)->bot->hash_table[0]->method->comand->comand_name = ft_strdup((ft_strsplit((*corewar)->bot->info[2], ' '))[1]);
	(*corewar)->bot->hash_table[0]->method->comand->args->arg_type = "T_REG";
	(*corewar)->bot->hash_table[0]->method->comand->args->ne


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
