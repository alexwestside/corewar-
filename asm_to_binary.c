
#include "op.h"
#include "corewar.h"

#define HEX_BASE "0123456789abcdef"


//size_t two_dem_strlen(char **s)
//{
//	char **p;
//
//	p = s;
//	while (*p)
//		p++;
//	return ((p - s) + 1);
//}
//
//void init_corewar(t_corewar **corewar)
//{
//	*corewar = (t_corewar *) malloc(sizeof(t_corewar));
//	ft_bzero(&(*corewar)->registrs, sizeof(int) * 16);
//	(*corewar)->bot = (t_bot *) malloc(sizeof(t_bot));
//	(*corewar)->bot->info = (char **) malloc(sizeof(char *));
//	(*corewar)->bot->info[0] = NULL;
//	(*corewar)->table = NULL;
////	(*corewar)->bot->hash_table = (t_hash_table **)malloc(sizeof(t_hash_table*) * 2);
////	(*corewar)->bot->hash_table[0] = (t_hash_table *)malloc(sizeof(t_hash_table));
////	(*corewar)->bot->hash_table[0]->method = (t_method *)malloc(sizeof(t_method));
////	(*corewar)->bot->hash_table[0]->method->comand = (t_comand *)malloc(sizeof(t_comand));
////	(*corewar)->bot->hash_table[0]->method->comand->args = (t_args *)malloc(sizeof(t_args));
////	(*corewar)->bot->hash_table[1] = (t_hash_table *)malloc(sizeof(t_hash_table));
////	(*corewar)->bot->hash_table[1]->method = (t_method *)malloc(sizeof(t_method));
////	(*corewar)->bot->hash_table[1]->method->comand = (t_comand *)malloc(sizeof(t_comand));
////	(*corewar)->bot->hash_table[1]->method->comand->args = (t_args *)malloc(sizeof(t_args));
//}

//void read_bot_info(t_bot *bot)
//{
//	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/corewar/resources/corewar/champs/examples/zork.s", O_RDONLY);
//	size_t i = 0;
//
//	while (get_next_line(fd, &(bot)->info[i]))
//	{
//		if ((bot)->info[i][0])
//		{
//			(bot)->info = (char **) realloc((bot)->info, sizeof(char *) * (i + 2));
//			i++;
//		}
//	}
//	(bot)->info[i] = NULL;
//}
//
//void init_hash(t_corewar **corewar)
//{
////	(*corewar)->bot->name = ft_strdup((ft_strsplit((*corewar)->bot->info[0], ' '))[1]);
////	(*corewar)->bot->comment = ft_strjoin(ft_strdup((ft_strsplit((*corewar)->bot->info[1], ' '))[1]), ft_strdup((ft_strsplit((*corewar)->bot->info[1], ' '))[2]));
////	(*corewar)->bot->hash_table[0]->method->method_name = ft_strdup((ft_strsplit((*corewar)->bot->info[2], '\t'))[0]);
////	(*corewar)->bot->hash_table[0]->method->comand->comand_name = ft_strdup((ft_strsplit((*corewar)->bot->info[2], ' '))[1]);
////	(*corewar)->bot->hash_table[0]->method->comand->args->arg_type = "T_REG";
////	(*corewar)->bot->hash_table[0]->method->comand->args->ne
//
//
//}

void hex(int n, int fd)
{
	if (n >= 16)
	{
		hex(n / 16, fd);
		hex(n % 16, fd);
	}
	else
		ft_putchar_fd(HEX_BASE[n], fd);
}

void hex_magic(int n, int fd, char *str, size_t *i)
{
	if (n >= 16)
	{
		hex_magic(n / 16, fd, str, i);
		hex_magic(n % 16, fd, str, i);
	}
	else
	{
		str[*i] = HEX_BASE[n];
		(*i)++;
		str = realloc(str, *i + 1);
	}
}

void str_to_hex(char *str, int fd, int len)
{



	while (len--)
	{
//		if (*str)
//		{
		hex(*str, fd);
		str++;
//		}
//		else
//			ft_putstr_fd("00", fd);
	}
}

void print_hex_magic(char *str, int fd)
{
	int i = 0;
	char *p = str;

	while (*str)
	{
		if (ft_strlen(p) + i < 8)
		{
			ft_putchar_fd(0, fd);
			i++;
		}
		else
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}

unsigned int reverse_magic(unsigned int magic)
{
	unsigned int res = 0;
	unsigned int i = 0;

	while (i < 4)
	{
		const unsigned int byte = (magic >> 8 * i) & 0xff;
		res |= byte << (24 - 8 * i);
		i++;
	}
	return res;
}

//t_bot hell_init(t_corewar *corewar)
//{
//	t_bot bot =
//			{
//					corewar->bot->info,
//					/*"zork"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[0], ' ')[1], '"')[0]),
//					/*"I'M ALIIIIVE"*/ft_strdup(ft_strjoin(ft_strjoin(ft_strsplit(ft_strsplit(corewar->bot->info[1], ' ')[1], '"')[0], " "), ft_strsplit(ft_strsplit(corewar->bot->info[1], ' ')[2], '"')[0])),
//					{{/*"l2"*/ft_strdup(ft_strsplit(corewar->bot->info[2], LABEL_CHAR)[0]),
//							  {{/*"sti"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[2], ' ')[0], '\t')[1]),
//										 {{/*"r1"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[2], '\t')[1], SEPARATOR_CHAR)[0], ' ')[1]), "1"},
//										  {/*"%:live"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[2], '\t')[1], SEPARATOR_CHAR)[1], ' ')[0]), "2"},
//										  {/*"%1"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[2], '\t')[1], SEPARATOR_CHAR)[2], ' ')[0]), "3"}}},
//							   {/*"and"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[3], ' ')[0], '\t')[0]),
//										 {{/*"r1"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[3], '\t')[0], SEPARATOR_CHAR)[0], ' ')[1]), "1"},
//										  {/*"%0"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[3], '\t')[0], SEPARATOR_CHAR)[1], ' ')[0]), "2"},
//										  {/*"r1"*/ft_strdup(ft_strsplit(ft_strsplit(ft_strsplit(corewar->bot->info[3], '\t')[0], SEPARATOR_CHAR)[2], ' ')[0]), "3"}}}}},
//					 {/*"live"*/ft_strdup(ft_strsplit(corewar->bot->info[4], LABEL_CHAR)[0]),
//								{{/*"live"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[4], '\t')[1], ' ')[0]),
//											{{/*"%1"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[4], '\t')[1], ' ')[1]), "1"},
//											 {NULL},
//											 {NULL}}},
//								 {/*"zjmp"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[5], '\t')[0], ' ')[0]),
//											{{/*"%:live"*/ft_strdup(ft_strsplit(ft_strsplit(corewar->bot->info[5], '\t')[0], ' ')[1]),  "2"},
//											 {NULL},
//											 {NULL}}}}}},
//			};
//	return (bot);
//}


//int type_comand(char *str, int fd)
//{
//	int opcode = 0;
//	int i = 0;
//
//	while (i < REG_NUMBER)
//	{
//		if (!ft_strcmp(str, op_tab[i].command_name))
//			break;
//		i++;
//	}
//	return (op_tab[i].opcode);
//}

int ft_isdigit_str(char *s)
{
	char *p;

	p = s;
	while(*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int type_args(char *str)
{
	char *s;

	s = str;
	if (*s == 'r')
		return (T_REG);
	if (*s == '%' && *(s + 1) == LABEL_CHAR)
		return (T_DIR);
	if (*s == '%' && ft_isdigit_str(ft_strndup(s + 1, ft_strlen(s) - 1)))
		return (T_DIR);
	return (0);
}

int by_type_args(int i, int arg)
{
	int res;

	res = 0;
	if (arg == T_REG)
		res = REG_CODE << (6 - (i != 2 ? i * 2 : 4));
	if (arg == T_DIR)
		res = DIR_CODE << (6 - (i != 2 ? i * 2 : 4));;
	if (arg == T_IND)
		res = IND_CODE << (6 - (i != 2 ? i * 2 : 4));;
	return (res);
}

//void bot_code_to_binary(t_corewar *corewar, int fd)
//{
//	int hash = 0;
//	int comm;
//	int arg;
//	int opcode;
//	int args = 0;
//
//	while (hash < 2)
//	{
//		comm = 0;
//		while (comm < 2)
//		{
//			opcode = type_comand(corewar->bot->hash_table[hash].method.comand[comm].comand_name, fd);
//			write(fd, &opcode, sizeof(char));
//			arg = 0;
//			while (arg < 3)
//			{
//				args += by_type_args(arg, type_args(corewar->bot->hash_table[hash].method.comand[comm].args[arg].arg_type));
//				arg++;
//			}
//			write(fd, &args, sizeof(char));
//			comm++;
//		}
//		hash++;
//	}
//
//
//}

void asm_to_binary(t_corewar *corewar)
{
	header_t *header = (header_t *) malloc(sizeof(header_t));
	header->magic = COREWAR_EXEC_MAGIC;
	bzero(header->prog_name, header->prog_size);
	bzero(header->comment, header->prog_size);
//	char *name = ft_strsplit(ft_strsplit(corewar->bot->info[0], ' ')[1], '"')[0];
//	char *comment = ft_strjoin(ft_strjoin(ft_strsplit(ft_strsplit(corewar->bot->info[1], ' ')[1], '"')[0], " "), ft_strsplit(ft_strsplit(corewar->bot->info[1], ' ')[2], '"')[0]);



	ft_memcpy(header->prog_name, corewar->bot.name, ft_strlen(corewar->bot.name));
	ft_memcpy(header->comment, corewar->bot.comment, ft_strlen(corewar->bot.comment));

	char *file_path = ft_strjoin("../", ft_strjoin(header->prog_name, ".cor"));
	int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

//	unsigned int magic = COREWAR_EXEC_MAGIC;
	unsigned int magic = reverse_magic(COREWAR_EXEC_MAGIC);
	write(fd, &magic, sizeof(magic) + sizeof(unsigned int) - sizeof(magic));
	write(fd, header->prog_name, (sizeof(*header->prog_name) * (PROG_NAME_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->prog_name))));
	write(fd, &header->prog_size, (sizeof(header->prog_size) + sizeof(unsigned int) - sizeof(header->prog_size)));
	write(fd, header->comment, sizeof(*header->comment) * COMMENT_LENGTH + 1 + sizeof(unsigned int) - sizeof(*header->comment));

//	corewar->op = init_op();
//	t_bot bot = hell_init(corewar);
//	corewar->bot[0] = hell_init(corewar);
//	bot_code_to_binary(corewar, fd);
	close(fd);

//	int d;
//	for (register d; )
	/*//*/
	/*//*/
	/*//*/

}

void _asm(t_corewar corewar)
{

//	char *s = malloc(0);
//	t_corewar *corewar;
//
//	init_corewar(&corewar);
//	read_bot_info(corewar->bot);
//	valid_bot(bot);

	asm_to_binary(&corewar);

//	init_hash(&corewar);
//	make_asm(&bot);

}
