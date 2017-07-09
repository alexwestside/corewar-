#include "corewar.h"

int 		collision(unsigned int *keys, unsigned int key)
{
	int 	i;

	i = -1;
	while (keys[++i] != 0)
		if (keys[i] == key)
			return (i);
	return (0);
}
