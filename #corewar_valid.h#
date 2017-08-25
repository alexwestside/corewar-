#ifndef COREWAR_VALID_H
#define COREWAR_VALID_H

#include "corewar.h"
#include "asm.h"

int				is_method(char *str);
int				is_comment(char *str);
int				is_name(char *str);
char			**open_read(char *av);
t_bot			ft_command(char **text);
void			ft_name_comment(char **name, char **comment, char ***text);
unsigned int	hash_key(char *str);
void			error(char *str);
int				collision(unsigned int *keys, unsigned int key);
void			_asm(t_corewar corewar);
int				ft_arg_type(char *str);
char			**ft_strsplit_2args(char const *s, char c1, char c2);
size_t			ft_strclen(char *str, char c);
t_hash_table	*get_table(t_hash_table **hash_table, unsigned int *keys, char *method);
void			valid(char **text, t_corewar *corewar);
void			ft_valid_command(t_command *command, t_hash_table **hash_table, unsigned int *keys);
char			*get_command_name(t_hash_table **hash_table, unsigned int *keys, char *method);
t_command		*get_table_command(t_hash_table **hash_table, unsigned int *keys, char *method);
#endif
