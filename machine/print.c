
#include "machine.h"

void	head_print(t_machine vm)
{
	unsigned i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while ( ++i < vm.count_players)
		ft_printf("%c Player %u, weighing %u, \"%s\" (\"%s\") !\n", '*',  i + 1,
				  vm.players[i].prog_size, vm.players[i].prog_name,
				  vm.players[i].comment);
}

