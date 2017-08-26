/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_valid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:55:31 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:55:35 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VALID_H
# define COREWAR_VALID_H

# include "corewar.h"
# include "asm.h"

typedef struct			s_hash_key
{
	t_hash_table		**hash_table;
	unsigned int		*key;
}						t_hash_key;

int						is_method(char *str);
int						is_comment(char *str);
int						is_name(char *str);
char					**open_read(char *av);
void					ft_name_comment(char **name, char **comment,
				char ***text);
void					ft_add_command(t_command **command, char *name,
				char **a);
void					ft_get_method(char ***text, t_hash_table ***hash_table,
				unsigned int **key, int *i);
unsigned int			hash_key(char *str);
void					error(char *str);
int						collision(unsigned int *keys, unsigned int key);
int						ft_arg_type(char *str);
char					**ft_strsplit_2args(char const *s, char c1, char c2);
size_t					ft_strclen(char *str, char c);
t_hash_table			*get_table(t_hash_table **hash_table,
				unsigned int *keys, char *method);
void					valid(char **text, t_corewar *corewar);
void					ft_valid_command(t_command *command,
				t_hash_table **hash_table, unsigned int *keys);
char					*get_command_name(t_hash_table **hash_table,
				unsigned int *keys, char *method);
t_command				*get_table_command(t_hash_table **hash_table,
				unsigned int *keys, char *method);
void					char_error(char *str, int i);
void					valid_args(t_op *tmp, t_args *args, int count_args,
				t_hash_key p);
void					valid_command(t_command *command,
				t_hash_table **hash_table, unsigned int *keys);
void					valid_name_method(char *str);
void					check_dir(char *str, t_hash_table **hash_table,
				unsigned int *keys);
void					check_reg(char *str);
void					check_ind(char *str);
void					check_args(t_args *args, char *str, int count);
void					lexical_error(char *str, int i);
t_bot					ft_command(char **text, int i, t_bot bot);

#endif