#ifndef DASM_H
# define DASM_H
# define BLUE "\033[0;36m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define END "\033[0m"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include "op.h"

typedef struct			s_command
{
	char 				*command_name;
	unsigned int		size;
	int					cod_octal;
	int					opcode;
	char 				*args[3];
	struct s_command	*next;
}						t_command;

#endif