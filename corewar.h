
#ifndef COREWAR_H
# define COREWAR_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct			s_args
{
	char 				*arg_type;
	int					data;

	struct s_args		*next;
}						t_args;

typedef struct			s_comand
{
	char				*comand_name;

	struct s_comand		*next;
}						t_comand;

typedef struct			s_hash_table
{
	int					key;
	t_comand			*comand;
}						t_hash_table;

typedef struct			s_bot
{
	char				**info;
	char				*name;
	char 				*comment;
	t_hash_table 		**hash_table;
}						t_bot;

void read_bot_info(t_bot **bot);



/*init*/
void init_bot(t_bot **bot);


/*sub*/
char					**ft_realloc(char ***std_in, unsigned long int len);
unsigned long int		two_dem_strlen(char **s);

#endif
