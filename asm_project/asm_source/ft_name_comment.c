/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:57:14 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:57:15 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

void		ft_name(char **name, char ***text, char *str, char *p)
{
	if (!p || !*p)
		error("Syntax error");
	else
	{
		if (ft_strchr(++p, '"'))
		{
			str = ft_strjoin(str, ft_strndup(p, ft_strclen(p, '"')));
			char_error(p, 0);
		}
		else
			while (++(*text))
			{
				char_error(**text, 2);
				if (ft_strchr(**text, '"'))
				{
					char_error(**text, 0);
					str = ft_strjoin(str, ft_strndup(**text,
						ft_strclen(**text, '"')));
					break ;
				}
				str = ft_strjoin(str, **text);
			}
	}
	*name = str;
}

void		ft_comment(char **comment, char ***text, char *str, char *p)
{
	if (!p || !*p)
		error("Syntax error");
	else
	{
		if (ft_strchr(++p, '"'))
		{
			str = ft_strjoin(str, ft_strndup(p, ft_strclen(p, '"')));
			char_error(p, 0);
		}
		else
			while (++(*text))
			{
				char_error(**text, 1);
				if (ft_strchr(**text, '"'))
				{
					char_error(**text, 0);
					str = ft_strjoin(str, ft_strndup(**text,
						ft_strclen(**text, '"')));
					break ;
				}
				str = ft_strjoin(str, **text);
			}
	}
	*comment = str;
}

int			is_name(char *str)
{
	char	**a;

	if (str && *str)
	{
		if (ft_strstr(str, NAME_CMD_STRING))
		{
			a = ft_strsplit_2args(str, ' ', '\t');
			if (!ft_strcmp(a[0], NAME_CMD_STRING))
				return (1);
			else if (*a[0] == COMMENT_CHAR || *a[0] == COMMENT_CHAR2)
				error("Syntax error");
			else
				error("Lexical error");
		}
	}
	return (0);
}

int			is_comment(char *str)
{
	char	**a;

	if (str && *str)
	{
		if (ft_strstr(str, COMMENT_CMD_STRING))
		{
			a = ft_strsplit_2args(str, ' ', '\t');
			if (!ft_strcmp(a[0], COMMENT_CMD_STRING))
				return (1);
			else if (*a[0] == COMMENT_CHAR || *a[0] == COMMENT_CHAR2)
				error("Syntax error");
			else
				error("Lexical error");
		}
	}
	return (0);
}

void		ft_name_comment(char **name, char **comment, char ***text)
{
	*name = NULL;
	*comment = NULL;
	while (**text && !is_method(**text))
	{
		if (is_name(**text) == 1)
			ft_name(name, text, "", ft_strchr(**text, '"'));
		else if (is_comment(**text) == 1)
			ft_comment(comment, text, "", ft_strchr(**text, '"'));
		else if (***text != COMMENT_CHAR && ***text != COMMENT_CHAR2)
			error("Syntax error");
		if (*name != NULL && *comment != NULL)
		{
			(*text)++;
			break ;
		}
		(*text)++;
	}
	if (*name == NULL)
		error("Lexical error");
	if (*comment == NULL)
		error("Lexical error");
}
