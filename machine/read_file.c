
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

char	*reverse_magic2(char *str, size_t size)
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

int 	read_data(t_machine *vm, int fd, int index_player)
{
	int		j;
	char 	*buf;
	int 	rd;
	size_t buff[] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH, COMMENT_LENGTH, CHAMP_MAX_SIZE + 1};

	j = -1;
	rd = 0;
	while (++j < MAX_ARGS_NUMBER && rd != -1) // count buff
	{
		buf = (char *)malloc(buff[j]);
		rd = (int)read(fd, buf, buff[j]);
		if (rd != -1 && j == 0)
			vm->players[index_player].magic = *(unsigned*)reverse_magic2(buf, buff[j]);
		else if (rd != -1 && j == 1)
			ft_memcpy(vm->players[index_player].prog_name, buf, (size_t)rd);
		else if (rd != -1 && j == 2)
			ft_memcpy(vm->players[index_player].comment, buf, (size_t)rd);
			//todo skip n byte and read code player
		else if (rd != -1 && j == 3)
		{
//			ft_putchar('\n');
			vm->players[index_player].prog_size = (unsigned)rd;
//			ft_memcpy(vm->code_players[index_player], buf, (size_t)rd);
//			for (int i = 0; i < rd + 1; i++)
//				ft_printf("%02x ", (unsigned char)buf[i]);
//			write(1, buf, (size_t)rd);
//			ft_putchar('\n');
		}
		free(buf);
	}
	return (0);
}
