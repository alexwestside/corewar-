#include "corewar.h"

int 	len_char(char **a)
{
	int len;

	len = 0;
	while (a[len] != NULL)
		len++;
	return (len);
}

void				get_method(char ***a, t_command **method)
{
	t_command		*head;
	t_command		*tmp;
	char 			**s;
	char			**p;

	while (**a && ***a == '\t')
	{
		tmp = (t_command *)malloc(sizeof(t_command));
		tmp->method = NULL;
		tmp->next = NULL;
		s = ft_strsplit(*ft_strsplit(**a, '\t'), ' ');
		tmp->command_name = ft_strdup(*(s++));
		if (s[0])
		{
			tmp->arg[0].data = ft_strdup(s[0]);
			tmp->arg[0].arg_type = ft_arg_type(s[0]);
			if (s[1])
			{
				tmp->arg[1].data = ft_strdup(s[1]);
				tmp->arg[1].arg_type = ft_arg_type(s[1]);
				if (s[2])
				{
					tmp->arg[2].data = ft_strdup(s[2]);
					tmp->arg[2].arg_type = ft_arg_type(s[2]);
				}
			}
		}
		if (*method == NULL)
			*method = tmp;
		else
		{
			head = *method;
			while ((*method)->next != NULL)
				*method = (*method)->next;
			(*method)->next = tmp;
			*method = head;
		}
		(*a)++;
	}
}

t_hash_table		*get_hash(char ***text, char **a)
{
	t_hash_table	*table;

	table = (t_hash_table *)malloc(sizeof(t_hash_table));
	table->command = NULL;
	table->collision = NULL;
	table->lable = ft_strdup(*(a++));
	++(*text);
	get_method((*a == NULL ? text : &a), &table->command);
	return (table);
}

int 				is_method(char *str)
{
	int 			i;
	char 			*s;

	s = str;
	i = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			i = 1;
		if (*s == ':')
			return (i == 0 ? 1 : 0);
		s++;
	}
	return (0);
}

int 				ft_arg_type(char *str)
{
	if (*str == '%')
		return (T_DIR);
	if (*str == 'r')
		return (T_REG);
	return (T_IND);
}

int 				ft_len_two_arr(char **a)
{
	int 			i;

	i = 0;
	while (a[i] != NULL)
		i++;
	return (i);
}

void				ft_add_command(t_command **command, char *name, char **a)
{
	t_command		*tmp;
	t_command		*head;
	int 			i;

	i = -1;
	tmp = (t_command *)malloc(sizeof(t_command));
	tmp->next = NULL;
	tmp->method = NULL;
	tmp->command_name = NULL;
	if (name != NULL)
		tmp->method = ft_strndup(name, ft_strclen(name, ':'));
	else
		while (a[++i] != NULL)
		{
			tmp->count_args = ft_len_two_arr(a) - 1;
			i == 0 ? tmp->command_name = ft_strdup(a[0]) : 0;
			if (i == 1)
			{
				tmp->arg[0].data = ft_strndup(a[1], ft_strclen(a[1], ','));
				tmp->arg[0].arg_type = ft_arg_type(a[1]);
			}
			if (i == 2)
			{
				tmp->arg[1].data = ft_strndup(a[2], ft_strclen(a[2], ','));
				tmp->arg[1].arg_type = ft_arg_type(a[2]);
			}
			if (i == 3)
			{
				tmp->arg[2].data = ft_strndup(a[3], ft_strclen(a[3], ','));
				tmp->arg[2].arg_type = ft_arg_type(a[3]);
			}
		}
	if (*command == NULL)
		*command = tmp;
	else
	{
		head = *command;
		while ((*command)->next != NULL)
			*command = (*command)->next;
		(*command)->next = tmp;
		*command = head;
	}
}

size_t				ft_strclen(char *str, char c)
{
	size_t				i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void				ft_get_method(char ***text, t_hash_table ***hash_table, unsigned int **key, int *i)
{
	char 			**a;
	t_hash_table	*tmp;
	unsigned int	j;
	int 			col;
	t_hash_table	*head;

	tmp = (t_hash_table*)malloc(sizeof(t_hash_table));
	tmp->lable = ft_strndup(**text, ft_strclen(**text, ':'));
	tmp->command = NULL;
	tmp->collision = NULL;
	**text = ft_strchr(**text, ':');
	(**text)++;
	while (**text != NULL && is_method(**text) != 1)
	{
		if (***text != '\0' && ***text != '#' && ***text != '\n')
		{
			a = ft_strsplit_2args(**text, ' ', '\t');
			ft_add_command(&tmp->command, NULL, a);
		}
		(*text)++;
	}
	j = hash_key(tmp->lable);
	if ((col = collision(*key, j)) == 0)
	{
		(*key)[*i] = j;
		*key = realloc(*key, (sizeof(*key) * (*i + 2)));
		(*hash_table)[*i] = tmp;
		*hash_table = realloc(*hash_table, (sizeof(*hash_table) * (*i + 2)));
		(*i)++;
	}
	else
	{
		head = *hash_table[col];
		while ((*hash_table[col])->collision != NULL)
			*hash_table[col] = (*hash_table[col])->collision;
		(*hash_table[col])->collision = tmp;
		*hash_table[col] = head;
	}
}

t_bot				ft_command(char **text)
{
	t_hash_table	**hash_table;
	unsigned int	*key;
	t_bot			bot;
	int 			i;
	char 			**a;

	i = 0;
	bot.command = NULL;
	hash_table = (t_hash_table **)malloc(sizeof(t_hash_table *));
	key = (unsigned int *)malloc(sizeof(unsigned int));
	while (*text != NULL)
	{
		if (**text == '#' || **text == '\0')
			text++;
		else
		{
			if (is_method(*text) == 1)
			{
				ft_add_command(&bot.command, *text, NULL);
				ft_get_method(&text, &hash_table, &key, &i);
			}
			else
			{
				a = ft_strsplit_2args(*text, ' ', '\t');
				ft_add_command(&bot.command, NULL, a);
				text++;
			}
		}
	}
	bot.hash_table = hash_table;
	bot.keys = key;
	return (bot);
}
