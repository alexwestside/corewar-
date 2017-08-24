#include "corewar_valid.h"

unsigned int		hash_key(char *str)
{
    unsigned int hash;

    hash = 0;
    while (*str)
    {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
        str++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

char	*get_command_name(t_hash_table **hash_table, unsigned int *keys, char *method)
{
    unsigned int	key;
    int 			i;

    key = hash_key(method);
    i = 0;
    while (keys[i] != key)
        i++;
    return (hash_table[i]->command->command_name);
}

t_hash_table	*get_table(t_hash_table **hash_table, unsigned int *keys, char *method)
{
    unsigned int	key;
    int 			i;

    key = hash_key(method);
    i = 0;
    while (keys[i] && keys[i] != key)
        i++;
    return (keys[i] ? hash_table[i] : NULL);
}

t_command	*get_table_command(t_hash_table **hash_table, unsigned int *keys, char *method)
{
    unsigned int	key;
    int 			i;

    key = hash_key(method);
    i = 0;
    while (keys[i] && keys[i] != key)
        i++;
    return (keys[i] ? hash_table[i]->command : NULL);
}

int collision(unsigned int *keys, unsigned int key)
{
    int i;

    i = -1;
    while (keys[++i] != 0)
        if (keys[i] == key)
            return (i);
    return (0);
}