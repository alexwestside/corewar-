#include "corewar.h"

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
