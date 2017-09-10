/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 13:53:06 by orizhiy           #+#    #+#             */
/*   Updated: 2017/08/26 16:07:06 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define HASH_TABLE_SIZE sizeof(t_has_table)
# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include "../../libft/ft_printf.h"
# include "./op.h"

typedef struct			s_args
{
	int					arg_type;
	char				*data;
}						t_args;

typedef struct			s_command
{
	char				*method;
	char				*command_name;
	t_args				arg[3];
	int					count_args;
	struct s_command	*next;
}						t_command;

typedef struct			s_hash_table
{
	char				*lable;
	t_command			*command;
	struct s_hash_table	*collision;
}						t_hash_table;

typedef struct			s_bot
{
	char				*name;
	char				*comment;
	t_hash_table		**hash_table;
	unsigned int		*keys;
	t_command			*command;
	char				**checkdup;
}						t_bot;

typedef struct			s_corewar
{
	t_bot				bot;
}						t_corewar;

#endif
