#include "corewar.h"

void	ft_name(char **name, char ***text)
{
	char **s;

	if (!ft_strstr(**text, ".name"))
		error("Syntax error at token [TOKEN][004:001] LABEL \"l2:\"");
	else
	{
		s = ft_strsplit(**text, '"');
		s++;
		if (*s == NULL)
			error(NULL);
		//else if (**s != '"')
		//	error("Lexical error at [2:10]");
		else
			*name = ft_strdup(*s);
		(*text)++;
	}
}

void	ft_comment(char **comment, char ***text)
{
	char **s;

	if (!ft_strstr(**text, ".comment"))
		error("Syntax error at token [TOKEN][004:001] LABEL \"l2:\"");
	else
	{
		s = ft_strsplit(**text, '"');
		s++;
		if (*s == NULL)
			error(NULL);
			//else if (**s != '"')
			//	error("Lexical error at [2:10]");
		else
			*comment = ft_strdup(*s);
		(*text)++;
	}
}

void 	ft_name_comment(char **name, char **comment, char ***text)
{
	int i;
	char **s;

	i = 0;
	while (***text == '#' || ***text == '\0')
		(*text)++;
	ft_name(name, text);
	ft_comment(comment, text);
}