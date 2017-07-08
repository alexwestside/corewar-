#include "machine.h"

void usage(int count, char *s)
{
	if (count == 1)
	{
		ft_putstr("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
		exit(0);
	}
}
