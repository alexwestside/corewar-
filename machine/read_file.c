
#include "machine.h"
#include <stdio.h>

void	switch_data(t_machine *vm, char *data, int index_player, int i)
{
	size_t size;

	size = sizeof(data);
	if (i == 0)
		vm->players[index_player].magic = (unsigned)size;
	else if (i == 1)
		ft_strncpy(vm->players[index_player].prog_name, data, size);
	else if (i == 2)
		ft_strncpy(vm->players[index_player].comment, data, size);
	else if (i == 3)
	{
		vm->players[index_player].prog_size = (unsigned)size;
//		strncpy(vm->code_players[index_player], data, size);
	}
}

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

int 	read_data(t_machine *vm, int fd, int i)
{
	int		j;
	char 	*buf;
	size_t buff[] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH, COMMENT_LENGTH, CHAMP_MAX_SIZE + 1};

	j = -1;
	while (++j < MAX_ARGS_NUMBER) // count buff
	{
		if (!(buf = ft_strnew(buff[j])) || custom_read(fd, buf, buff[j], j) == -1)
//		if (!(buf =(unsigned char *)malloc(si)) || custom_read(fd, buf, buff[j], j) == -1)
		{
			free(buf);
			return (-1);
		}
		switch_data(vm, buf, i, j);
		free(buf);
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

int 	custom_read(int fd, char *buff, size_t size_buff, int check)
{
	int			data;

	data = (int)read(fd, buff, size_buff);
	if (data != -1 && check == 0)
		if (COREWAR_EXEC_MAGIC != *(unsigned *)reverse_magic2(buff, size_buff))
		{
			printf("res work \n");
			return (-1);
		}
	else
		return (data);
	else if (data != -1 && (check == 1 || check == 2))
		buff[size_buff] = '\0';
	else if (data != -1 && check == 3 && data > CHAMP_MAX_SIZE)
		return (-1);
	return (data);
}
