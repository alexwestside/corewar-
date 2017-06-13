
#ifndef COREWAR_H
# define COREWAR_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct			s_args
{
	char 				*arg_type;
	char				*data;
	struct s_args		*next;
}						t_args;

typedef struct			s_comand
{
	char				*comand_name;
	t_args				*args;
	struct s_comand		*next;
}						t_comand;

typedef struct			s_method
{
	char				*method_name;
	t_comand			*comand;
}						t_method;

typedef struct			s_hash_table
{
	int					key;
	t_method			*method;
}						t_hash_table;

typedef struct			s_bot
{
	char				**info;
	char				*name;
	char 				*comment;
	t_hash_table 		**hash_table;
}						t_bot;

typedef struct			s_corewar
{
	char				*table;
	t_bot				*bot;
	int					registrs[16];
}						t_corewar;






/*init*/



/*sub*/
char					**ft_realloc(char ***std_in, unsigned long int len);
unsigned long int		two_dem_strlen(char **s);

#endif
