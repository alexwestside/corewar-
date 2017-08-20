

#include "machine.h"


void	op_aff(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	(void)args;
	(void)vm;
	if (vm->flags.flag == '\0')
		ft_printf("Aff: %c\n", fork->reg[args[0] - 1] % 256);
}
