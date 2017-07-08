#include "machine.h"

void usage(int count, char *s)
{
	if (count == 1)
	{
		ft_putstr("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
		exit(0);
	}
	else if (count == 2)
	{
		ft_putstr("File ");
		ft_putstr(s);
		ft_putendl(" is too small to be a champion");
		exit(0);
	}
	else
		exit(0);
}
