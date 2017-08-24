#include "corewar_valid.h"

int 				is_method(char *str)
{
    int 			i;
    char 			*s;

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

int            ft_arg_type(char *str)
{
    if (*str == DIRECT_CHAR)
        return (T_DIR);
    if (*str == 'r')
        return (T_REG);
    return (T_IND);
}

int 				ft_len_two_arr(char **a)
{
    int 			i;

    i = 1;
    while (a[i] != NULL && ft_strchr(a[i], SEPARATOR_CHAR))
        i++;
    return (i + 1);
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
        tmp->method = ft_strndup(name, ft_strclen(name, LABEL_CHAR));
    else
        while (a[++i] != NULL)
        {
            tmp->count_args = ft_len_two_arr(a) - 1;
            i == 0 ? tmp->command_name = ft_strdup(a[0]) : 0;
            if (i == 1)
            {
                tmp->arg[0].data = ft_strndup(a[1], ft_strclen(a[1], SEPARATOR_CHAR));
                tmp->arg[0].arg_type = ft_arg_type(a[1]);
            }
            if (i == 2)
            {
                tmp->arg[1].data = ft_strndup(a[2], ft_strclen(a[2], SEPARATOR_CHAR));
                tmp->arg[1].arg_type = ft_arg_type(a[2]);
            }
            if (i == 3)
            {
                tmp->arg[2].data = ft_strndup(a[3], ft_strclen(a[3], SEPARATOR_CHAR));
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
    tmp->lable = ft_strndup(**text, ft_strclen(**text, LABEL_CHAR));
    tmp->command = NULL;
    tmp->collision = NULL;
    **text = ft_strchr(**text, ':');
    (**text)++;
    while (**text != NULL && is_method(**text) != 1)
    {
        if (***text != '\0' && ***text != COMMENT_CHAR && ***text != COMMENT_CHAR2 && ***text != '\n')
        {
            a = ft_strsplit_2args(**text, ' ', '\t');
            if (a[0] && *a[0] != COMMENT_CHAR && *a[0] != COMMENT_CHAR2)
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
        if (**text == COMMENT_CHAR || **text == COMMENT_CHAR2 || !*text)
            text++;
        else
        {
            if (**text == ' ' || **text == '\t')
            {
                while (**text == ' ' || **text == '\t')
                    (*text)++;
                if (!**text)
                {
                    text++;
                    continue;
                }
            }
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
    ft_valid_command(bot.command, hash_table, key);
    bot.hash_table = hash_table;
    bot.keys = key;
    return (bot);
}
