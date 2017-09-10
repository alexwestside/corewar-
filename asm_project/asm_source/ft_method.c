/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:56:56 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:56:57 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

unsigned int				**ft_hash_table(t_hash_table ***hash_table,
					unsigned int **key, t_hash_table *tmp, int *i)
{
	unsigned int	j;
	int				col;
	t_hash_table	*head;

	j = hash_key(tmp->lable);
	if ((col = collision(*key, j)) == -1)
	{
		(*key)[*i] = j;
		*key = realloc(*key, (sizeof(*key) * (*i + 2)));
		(*hash_table)[*i] = tmp;
		*hash_table = realloc(*hash_table, (sizeof(*hash_table) * (*i + 2)));
		(*i)++;
	}
	else
	{
		head = (*hash_table)[col];
		while ((*hash_table)[col]->collision != NULL)
			(*hash_table)[col] = (*hash_table)[col]->collision;
		(*hash_table)[col]->collision = tmp;
		(*hash_table)[col] = head;
	}
	return (key);
}

unsigned int **ft_get_method(char ***text, t_hash_table ***hash_table,
					unsigned int **key, int *i)
{
	char			**a;
	t_hash_table	*tmp;

	tmp = (t_hash_table*)malloc(sizeof(t_hash_table));
	tmp->lable = ft_strndup(**text, ft_strclen(**text, LABEL_CHAR));
	tmp->command = NULL;
	tmp->collision = NULL;
	**text = ft_strchr(**text, LABEL_CHAR);
	(**text)++;
	while (**text != NULL && is_method(**text) != 1)
	{
		if (***text != '\0' && ***text != COMMENT_CHAR &&
				***text != COMMENT_CHAR2 && ***text != '\n')
		{
			if (ft_strstr(**text, NAME_CMD_STRING) || ft_strstr(**text, COMMENT_CMD_STRING))
				break ;
			a = ft_strsplit_3args(**text, ' ', '\t', SEPARATOR_CHAR);
			if (a[0] && *a[0] != COMMENT_CHAR && *a[0] != COMMENT_CHAR2)
				ft_add_command(&tmp->command, NULL, a);
		}
		(*text)++;
	}
	key = ft_hash_table(hash_table, key, tmp, i);
	return (key);
}
