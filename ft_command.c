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
	if (ft_strstr(str, ":") && !ft_strstr(str, "%"))
		return (1);
	return (0);
}

int 				ft_arg_type(char *str)
{
	if (*str == DIRECT_CHAR)
		return (T_DIR);
	if (*str == 'r')
		return (T_REG);
	return (T_DIR);
}

void				add_command(t_command **command, char **a, int flag)
{
	t_command		*tmp;
	t_command		*head;
	int 			i;
	char 			*str;
	size_t 			size;

	i = -1;
	tmp = (t_command *)malloc(sizeof(t_command));
	tmp->next = NULL;
	tmp->method = NULL;
	tmp->command_name = NULL;
	if (flag == 1)
	{
		//tmp->method = ft_str;
		//str = a[0];
		//while (*str != ':')
		//	str++;
		tmp->method = ft_strdup(a[0]);
	}
	else
		while (a[++i] != NULL)
		{
			i == 0 ? tmp->command_name = ft_strdup(a[0]) : 0;
			if (i == 1)
			{
				tmp->arg[0].data = ft_strdup(a[1]);
				tmp->arg[0].arg_type = ft_arg_type(a[1]);
			}
			if (i == 2)
			{
				tmp->arg[1].data = ft_strdup(a[2]);
				tmp->arg[1].arg_type = ft_arg_type(a[2]);
			}
			if (i == 3)
			{
				tmp->arg[2].data = ft_strdup(a[3]);
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

int 				is_command(char **a)
{
	int 			i;

	i = 0;
	while (a[i] != NULL)
		i++;
	return ((i == 1 || i == 0) ? 0 : 1);
}

t_bot				ft_command(char **text)
{
	t_hash_table	**hash_table;
	unsigned int	*key;
	char	**a;
	int i;
	unsigned int j;
	int 		col;
	t_hash_table	*tmp;
	t_hash_table	*head;
	t_bot			bot;

	i = 0;
	j = 0;
	bot.command = NULL;
	hash_table = (t_hash_table **)malloc(sizeof(t_hash_table *));
	key = (unsigned int *)malloc(sizeof(unsigned int));
	while (*text != NULL)
	{
		a = ft_strsplit(*text, ' ');
		if (*a[0] != '#' && *a[0] != '\0')
		{
			if (is_method(a[0]) == 1)
			{
				add_command(&bot.command, a, 1);
				j = hash_key(a[0]);
				if ((col = collision(key, j)) == 0)
				{
					key[i] = j;
					key = realloc(key, (sizeof(key) * (i + 2)));
					hash_table[i] = get_hash(&text, a);
					hash_table = realloc(hash_table, (sizeof(hash_table) * (i + 2)));
					i++;
				}
				else
				{
					tmp = get_hash(&text, a);
					head = hash_table[col];
					while (hash_table[col]->collision != NULL)
						hash_table[col] = hash_table[col]->collision;
					hash_table[col]->collision = tmp;
					hash_table[col] = head;
				}
			}
			else if (is_command(a) == 1)
			{
				add_command(&bot.command, a, 2);
				text++;
			}
			else
				text++;
		}
		else
			text++;
	}
	bot.hash_table = hash_table;
	bot.keys = key;
	return (bot);
}
