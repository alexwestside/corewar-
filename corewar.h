#ifndef COREWAR_H
# define COREWAR_H
# define HASH_TABLE_SIZE sizeof(t_has_table)
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
#include "op.h"

typedef struct			s_args
{
	int 				arg_type;
	char				*data;
}						t_args;

typedef struct			s_command
{
	char				*method;
	char 				*command_name;
	t_args				arg[3];
	int					count_args;
	struct s_command	*next;
}						t_command;

typedef struct			s_hash_table
{
	char 				*lable;
	t_command			*command;
	struct s_hash_table	*collision;
}						t_hash_table;

typedef struct			s_bot
{
	char 				*name;
	char 				*comment;
	t_hash_table 		**hash_table;
	unsigned int		*keys;
	t_command			*command;
}						t_bot;

typedef struct			s_corewar
{
	t_bot				bot;
	int					registrs[16];
}						t_corewar;

int			op(char *str);

/*init*/
/*sub*/
void		valid(char **text, t_corewar *corewar);
char					**ft_realloc(char ***std_in, unsigned long int len);
unsigned long int		two_dem_strlen(char **s);
char					**open_read(char *av);
t_bot					ft_command(char **text);
void 					ft_name_comment(char **name, char **comment, char ***text);
unsigned int			hash_key(char *str);
void		error(char *str);
int 		collision(unsigned int *keys, unsigned int key);

void _asm(t_corewar corewar);
int 				ft_arg_type(char *str);
char		**ft_strsplit_2args(char const *s, char c1, char c2);
size_t				ft_strclen(char *str, char c);
char	*get_command_name(t_hash_table **hash_table, unsigned int *keys, char *method);
t_hash_table	*get_table(t_hash_table **hash_table, unsigned int *keys, char *method);

#endif
