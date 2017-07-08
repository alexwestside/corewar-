
#include "machine.h"

void	format_player(char *fmt_st, char *fmt_end, const char *str)
{
	ft_putstr(fmt_st);
	ft_putstr(str);
	ft_putstr(fmt_end);
}

void	head_print(t_machine vm)
{
	unsigned i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm.count_players)
	{
		ft_printf("%c Player %u, weighing %u bytes, ", '*', i + 1, vm.players[i].prog_size);
		format_player("\"", "\"", vm.players[i].prog_name);
		ft_putchar(' ');
		format_player("(\"", "\")", vm.players[i].comment);
		ft_putstr(" !\n");
	}
}

void	test_print_code_player(t_machine vm)
{
	size_t  i;
	int j;

	i = -1;
	j = -1;
	while (++j < vm.count_players)
	{
		i = -1;
		ft_printf("\n\n size code player [%u]\n", vm.size_code_players[j]);
		ft_printf("\n\n byte code player [%d]\n", j);
		while (++i < vm.size_code_players[j])
		{
			ft_printf(" %02x", vm.code_players[j][i]);
		}
		ft_putchar('\n');
	}
}

void	console_print_arena(t_machine vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((i % PR_SIZE_ARENA) == 0)
			ft_printf("\n0x%04x :", i);
		ft_printf(" %02x", vm.arena[i]);
	}
	ft_putchar('\n');
}