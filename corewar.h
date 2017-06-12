
#ifndef COREWAR_H
# define COREWAR_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct	s_hash_table
{


}				t_s_hash_table;

typedef struct	s_bot
{
	char		**info;
}				t_bot;




void read_bot_info(t_bot **bot);



/*init*/
void init_bot(t_bot **bot);


/*sub*/
char					**ft_realloc(char ***std_in, unsigned long int len);
unsigned long int		two_dem_strlen(char **s);

#endif
