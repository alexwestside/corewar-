/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:58:12 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:58:12 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

unsigned int		hash_key(char *str)
{
	unsigned int	hash;

	hash = 0;
	while (*str)
	{
		hash += (unsigned char)(*str);
		hash += (hash << 10);
		hash ^= (hash >> 6);
		str++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

char				*get_command_name(t_hash_table **hash_table,
						unsigned int *keys, char *method)
{
	unsigned int	key;
	int				i;

	key = hash_key(method);
	i = 0;
	while (keys[i] != key)
		i++;
	return (hash_table[i]->command->command_name);
}

void				add_checkdup(char *method, char **checkdup, int i)
{
	if (checkdup)
	{
		while (checkdup && *checkdup && ft_strcmp(*checkdup, "1"))
			checkdup++;
		checkdup ? *checkdup = ft_strdup(method) : 0;
	}
}

t_hash_table		*get_table(t_hash_table **hash_table,
						unsigned int *keys, char *method, char **checkdup, int flag)
{
	unsigned int	key;
	int				i;

	key = hash_key(method);
	i = 0;
	while (keys[i] && keys[i] != key)
		i++;
	while (checkdup && *checkdup)
	{
		if (*checkdup && !ft_strcmp(*checkdup, method) && hash_table[i]->collision)
		{
			hash_table[i] = hash_table[i]->collision;
			flag == 1 ? add_checkdup(method, checkdup, i) : 0;
			return (hash_table[i]);
		}
		checkdup++;
	}
	flag == 1 ? add_checkdup(method, checkdup, i) : 0;
	return (keys[i] ? hash_table[i] : NULL);
}

t_command			*get_table_command(t_hash_table **hash_table,
						unsigned int *keys, char *method)
{
	unsigned int	key;
	int				i;

	key = hash_key(method);
	i = 0;
	while (keys[i] && keys[i] != key)
		i++;
	return (keys[i] ? hash_table[i]->command : NULL);
}

int					collision(unsigned int *keys, unsigned int key)
{
	int				i;

	i = -1;
	while (keys[++i] != 0)
		if (keys[i] == key)
			return (i);
	return (0);
}
