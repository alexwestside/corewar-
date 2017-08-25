#include "corewar_valid.h"

int					is_method(char *str)
{
	int				i;
	char			*s;

	s = str;
	i = 0;
	while (*s != '\0')
	{
		if (*s == DIRECT_CHAR)
			i = 1;
		if (*s == LABEL_CHAR)
			return (i == 0 ? 1 : 0);
		s++;
	}
	return (0);
}

int					ft_arg_type(char *str)
{
	if (*str == DIRECT_CHAR)
		return (T_DIR);
	if (*str == 'r')
		return (T_REG);
	return (T_IND);
}

size_t				ft_strclen(char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void				check_text_2(char ***text)
{
	if (***text == ' ' || ***text == '\t')
	{
		while (***text == ' ' || ***text == '\t')
			(**text)++;
		if (!***text)
			(*text)++;
	}
}

t_bot				ft_command(char **text, int i, t_bot bot)
{
	char			**a;

	while (*text)
	{
		if (**text == COMMENT_CHAR || **text == COMMENT_CHAR2 || !*text)
			text++;
		else
		{
			check_text_2(&text);
			if (is_method(*text) == 1)
			{
				ft_add_command(&bot.command, *text, NULL);
				ft_get_method(&text, &bot.hash_table, &bot.keys, &i);
			}
			else
			{
				a = ft_strsplit_2args(*text, ' ', '\t');
				ft_add_command(&bot.command, NULL, a);
				text++;
			}
		}
	}
	ft_valid_command(bot.command, bot.hash_table, bot.keys);
	return (bot);
}
