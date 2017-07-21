#include "corewar_valid.h"

t_op			*find_t_op(char *str)
{
	int			i;

	i = -1;
	if (str)
	{
		while (++i < 16)
			if (!ft_strcmp(op_tab[i].command_name, str))
				return (&op_tab[i]);
	}
	return (NULL);
}

void			check_args(t_args *args, char *str, int count)
{
	int 		i;

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
	i == count ? error(ft_strjoin("Invalid instruction \"", ft_strjoin(str, "\""))) : 0;
}

void			check_dir(char *str, t_hash_table **hash_table, unsigned int *keys)
{
	char 		*s;
	t_hash_table	*tmp;

	str++;
	if (!*str)
		error("Lexical error");
	else
	{
		if (*str == LABEL_CHAR)
		{
			str++;
			if (!*str)
				error("Lexical error");
			s = ft_strdup(str);
			while (*str)
			{
				if (!ft_strchr(LABEL_CHARS, *str))
					error("Lexical error");
				str++;
			}
			tmp = get_table(hash_table, keys, s);
			if (tmp == NULL)
				error("No such label");
		}
		else
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
	}
}

void			check_reg(char *str)
{
	char 		*s;
	int 		i;

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

void			check_ind(char *str)
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

void			valid_args(t_op *tmp, t_args *args, int count_args, t_hash_table **hash_table, unsigned int *keys)
{
	int 		i;
	int 		j;

	i = -1;
	while (++i < count_args)
	{
		j = -1;
		while (++j < 3)
		{
			if (args[i].arg_type == tmp->args[i][j])
				break;
			else if (j == 2 && args[i].arg_type != tmp->args[i][j])
				error("Invalid parameter 0 type");
		}
		if (args[i].arg_type == T_DIR)
			check_dir(args[i].data, hash_table, keys);
		else if (args[i].arg_type == T_REG)
			check_reg(args[i].data);
		else if (args[i].arg_type == T_IND)
			check_ind(args[i].data);
	}
}

void 			valid_command(t_command *command, t_hash_table **hash_table, unsigned int *keys)
{
	t_op		*tmp;

	tmp = find_t_op(command->command_name);
	if (tmp == NULL)
	{
		command->count_args > 0 ? check_args(command->arg, command->command_name, command->count_args) : 0;
		error("Syntax error");
	}
	else
	{
		if (tmp->count_args != command->count_args)
			error("Invalid parameter");
		valid_args(tmp, command->arg, command->count_args, hash_table, keys);

	}
}

void 			valid_name_method(char *str)
{
	while (str && *str)
	{
		if (!ft_strchr(LABEL_CHARS, *str))
			error("Lexical error");
		str++;
	}
}

void			ft_valid_command(t_command *command, t_hash_table **hash_table, unsigned int *keys)
{
	t_command	*p;

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
