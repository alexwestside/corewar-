
#include "machine.h"

int 	multi_parsing_files(t_machine *vm, char **strs)
{
	int 	i;
	int		fd;
	int		err;
	int		index;

	i = 0;
	err = 0;
	index = 0;
	while (strs[++i])
	{
		err += (fd = open(strs[i], O_RDONLY)) != -1 ? 1 : 0;
		if (err > vm->count_players)
		{
			fd != -1 ? close(fd) : 0;
			return (-1);
		}
		read_data(vm, fd, index);
		read_code_player(vm, fd, index);
		fd != -1 ? close(fd) : 0;
		index++;
	}
	return (0);
}

void printbincharpad(char c)
{
	for (int i = 7; i >= 0; --i)
	{
		putchar( (c & (1 << i)) ? '1' : '0' );
	}
	putchar(' ');
}

char	*reverse(char *str, size_t size)
{
	size_t i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = str[size - i - 1];
		str[size - i - 1] = str[i];
		str[i] = tmp;
		i++;
	}
	i = 0;
	printf("\n\nres reverse code byte \n");
	while (i < size)
	{
//		ft_printf(" ");
//		ft_printf("%02x:%c", (unsigned char)str[i], (unsigned char)str[i]);
		printbincharpad(str[i]);
		i++;
	}
	putchar('\n');
	return (str);
}

int 	read_data(t_machine *vm, int fd, int i)
{
	int		j;
	char 	*buf;
	int 	rd;
	static size_t st[] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH, 4,
						  sizeof(vm->players[i].prog_size), COMMENT_LENGTH};

	j = -1;
	rd = 0;
	while (++j <= MAX_ARGS_NUMBER && rd != -1)
	{
		buf = (char *)malloc(st[j]);
		if (!buf || ((rd = (int)read(fd, buf, st[j])) == -1))
			break ;
		j == 0 ? vm->players[i].magic = *(unsigned*)reverse(buf, st[j]) : 0;
		j == 1 ? ft_memcpy(vm->players[i].prog_name, buf, (size_t)rd) : 0;
		j == 2 && rd != st[j] ? rd = -1 : 0;
		j == 3 ? vm->players[i].prog_size = *(unsigned*)reverse(buf, st[j]) : 0;
		j == 4 ? ft_memcpy(vm->players[i].comment, buf, (size_t)rd) : 0;
		free(buf);
	}
	return (0);
}

int		read_code_player(t_machine *vm, int fd, int index)
{
	ssize_t rd;
	char 	buff[SIZE_BUFF];
	char 	*tmp;
	size_t 	sum;

	sum = 0;
	tmp = NULL;
	while ((rd = read(fd, buff, SIZE_BUFF)) > 0)
	{
		sum += rd;
		tmp = realloc(tmp, (size_t)rd);
		ft_memcpy(tmp, buff, (size_t)rd);
	}
	// todo fix vm->code_players[index]
	vm->code_players[index] = (unsigned char *)malloc(sum);
	vm->size_code_players[index] = sum;
	ft_memcpy(vm->code_players[index], tmp, sum);
	return (sum > 0 ? (int)sum : -1);
}
