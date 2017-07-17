#include "corewar_valid.h"

void 	ft_rewrite(char **s, char **str)
{
	char *quot;

	*str = "";
	while (s && *s)
	{
		if ((quot = ft_strchr(*s, '"')))
		{
			quot++;
			if (ft_strchr(quot, '"'))
				error("Syntax error");
			else
				*str = ft_strjoin(*str, ft_strndup(*s, ft_strclen(*s, '"')));
		}
		else
			*str = ft_strjoin(*str, *s);
		s++;
	}
}

void	ft_name(char **name, char ***text)
{
	char **s;
	char *str;

	str = "";
	s = ft_strsplit_2args(**text, ' ', '\t');
	if (!s[1])
		error("Syntax error");
	else
	{
		if (*s[1]++ != '"')
			error("Lexical error");
		else
		{
			ft_fin_write(&str, ++s);
			while (!ft_strchr(str, '"'))
			{
				(*text)++;
				if (!**text || is_name(**text) || is_method(**text))
					error("segmentation fault in origin asm");
				str = ft_strjoin(str, **text);
			}
			ft_rewrite(ft_strsplit_2args(str, ' ', '\t'), &str);
		}
	}
	*name = str;
}

void		ft_fin_write(char **str, char **s)
{
	while (s && *s)
	{
		*str = ft_strjoin(*str, *s);
		s++;
	}
}

void	ft_comment(char **comment, char ***text)
{
	char **s;
	char *str;

	str = "";
	s = ft_strsplit_2args(**text, ' ', '\t');
	if (!s[1])
		error("Syntax error");
	else
	{
		if (*s[1]++ != '"')
			error("Lexical error");
		else
		{
			ft_fin_write(&str, ++s);
			while (!ft_strchr(str, '"'))
			{
				(*text)++;
				if (!**text || is_name(**text) || is_method(**text))
					error("segmentation fault in origin asm");
				str = ft_strjoin(str, **text);
			}
			ft_rewrite(ft_strsplit_2args(str, ' ', '\t'), &str);
		}
	}
	*comment = str;
}

int 	is_name(char *str)
{
	char **a;

	a = NULL;
	if (str && *str)
	{
		if (ft_strstr(str, NAME_CMD_STRING))
		{
			a = ft_strsplit_2args(str, ' ', '\t');
			if (!ft_strcmp(a[0], NAME_CMD_STRING))
				return (1);
			else if (*a[0] == COMMENT_CHAR)
				error("Syntax error");
			else
				error("Lexical error");
		}
	}
	return (0);
}

int 	is_comment(char *str)
{
	char **a;

	a = NULL;
	if (str && *str)
	{
		if (ft_strstr(str, COMMENT_CMD_STRING))
		{
			a = ft_strsplit_2args(str, ' ', '\t');
			if (!ft_strcmp(a[0], COMMENT_CMD_STRING))
				return (1);
			else if (*a[0] == COMMENT_CHAR)
				error("Syntax error");
			else
				error("Lexical error");
		}
	}
	return (0);
}


void 	ft_name_comment(char **name, char **comment, char ***text)
{
	int 	i;

	i = 1;
	*name = NULL;
	*comment = NULL;
	while (**text && !is_method(**text))
	{
		if (is_name(**text) == 1)
			ft_name(name, text);
		else if (is_comment(**text) == 1)
			ft_comment(comment, text);
		else if (***text != COMMENT_CHAR)
			error("Syntax error");
		if (*name != NULL && *comment != NULL)
		{
			(*text)++;
			break;
		}
		(*text)++;
	}
	if (*name == NULL)
		error("Lexical error");
	if (*comment == NULL)
		error("Lexical error");
}