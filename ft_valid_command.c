#include "corewar_valid.h"

void				check_args(t_args *args, char *str, int count)
{
	int				i;

	i = -1;
	while (++i < count)
	{
		if (*(args[i].data) == DIRECT_CHAR)
			continue;
		else if (*(args[i].data) == 'r')
			continue;
		else
		{
			if (!ft_isdigit(*(args[i].data)) && *(args[i].data) != '-')
				error("Syntax error");
			while (*(args[i].data) && ft_isdigit(*(args[i].data)))
				(args[i].data)++;
			if (*(args[i].data))
				error("Syntax error");
		}
	}
	i == count ? error(ft_strjoin("Invalid instruction \"",
		ft_strjoin(str, "\""))) : 0;
}

void				check_dir(char *str, t_hash_table **hash_table,
						unsigned int *keys)
{
	char			*s;
	t_hash_table	*tmp;

	str++;
	lexical_error(str, 0);
	if (*str == LABEL_CHAR)
	{
		str++;
		lexical_error(str, 0);
		s = ft_strdup(str);
		while (*str)
			lexical_error(str++, 2);
		tmp = get_table(hash_table, keys, s);
		if (tmp == NULL)
			error("No such label");
	}
	else
	{
		if (*str && *str == '-')
			str++;
		lexical_error(str, 1);
		while (*str)
			lexical_error(str++, 1);
	}
}

void				check_reg(char *str)
{
	char			*s;
	int				i;

	str++;
	if (!*str)
		error("Syntax error");
	else
	{
		s = ft_strdup(str);
		if (!ft_isdigit(*str))
			error("Lexical error");
		while (*str)
		{
			if (!ft_isdigit(*str))
				error("Syntax error");
			str++;
		}
		i = ft_atoi(s);
		if (i < 1 || i > REG_NUMBER)
			error("REG not found");
	}
}

void				check_ind(char *str)
{
	if (*str && *str == '-')
		str++;
	if (!ft_isdigit(*str))
		error("Lexical error");
	while (*str)
	{
		if (!ft_isdigit(*str))
			error("Syntax error");
		str++;
	}
}

void				ft_valid_command(t_command *command,
						t_hash_table **hash_table, unsigned int *keys)
{
	t_command		*p;

	while (command != NULL)
	{
		if (command->method != NULL)
		{
			valid_name_method(command->method);
			p = get_table_command(hash_table, keys, command->method);
			while (p != NULL)
			{
				valid_command(p, hash_table, keys);
				p = p->next;
			}
		}
		else
			valid_command(command, hash_table, keys);
		command = command->next;
	}
}
