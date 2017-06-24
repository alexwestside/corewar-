
#include "machine.h"


char		*cust_strtrim(char const *s, size_t size)
{
	char	*f;
	char	*new;
	char	*copy_s;

	new = (char *)ft_memalloc(size);
	if (!s || !new)
		return (NULL);
	ft_memcpy(new, s, size);
	f = new;
	s = new;
	f += size;
	while (ft_isspace(*s) || (*s == '\0'))
		s++;
	while (ft_isspace(*f) || (*f == '\0'))
		f--;
	*++f = '\0';
	copy_s = ft_strdup(s);
	free(new);
	return (copy_s);
}

void	format_player(char *fmt_st, char *fmt_end, const char *str, size_t size)
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
		format_player("\"", "\"", vm.players[i].prog_name, PROG_NAME_LENGTH);
		ft_putchar(' ');
		format_player("(\"", "\")", vm.players[i].comment, COMMENT_LENGTH);
		ft_putstr(" !\n");
	}
}
