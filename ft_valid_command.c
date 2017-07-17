#include "corewar_valid.h"

t_op			*find_t_op(char *str)
{
	int			i;

	i = -1;
	while (++i < 16)
		if (!ft_strcmp(op_tab[i].command_name, str))
			return (&op_tab[i]);
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
			while (*(args[i].data) && ft_isdigit(*(args[i].data)))
				(args[i].data)++;
			if (*(args[i].data))
				break;
		}
	}
	i == count ? error(ft_strjoin("Invalid instruction \"", ft_strjoin(str, "\""))) : 0;
}

void 			valid_command(t_command *command)
{
	t_op		*tmp;

	tmp = find_t_op(command->command_name);
	if (tmp == NULL)
	{
		command->count_args > 0 ? check_args(command->arg, command->command_name, command->count_args) : 0;
		error("Syntax error");
	}
//	else
//	{
//
//	}
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
	t_hash_table	*p;

	while (command != NULL)
	{
		if (command->method != NULL)
		{
			valid_name_method(command->method);
			p = get_table(hash_table, keys, command->method);
			while (p->command != NULL)
			{
				valid_command(p->command);
				p->command = p->command->next;
			}
		}
		else
			valid_command(command);
		command = command->next;
	}
}
