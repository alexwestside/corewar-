
#include "machine.h"

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
		ft_strncpy(vm->code_players[index_player], data, size);
	}
}

int 	multi_parsing_files(t_machine *vm, char **strs)
{
	int		fd;
	int		err;
	int		index;
	char	*p;

	p = *strs;
	err = 0;
	index = 0;
	while (p)
	{
		err += (fd = open(p, O_RDONLY)) != -1 ? 1 : 0;
		if (err > vm->count_players)
		{
			fd != -1 ? close(fd) : 0;
			return (-1);
		}
		read_data(vm, fd, index);
		fd != -1 ? close(fd) : 0;
		index++;
		p++;
	}
	return (0);
}

int 	read_data(t_machine *vm, int fd, int i)
{
	int		j;
	char 	*buf;
	static	size_t buff[MAX_ARGS_NUMBER] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH + 1, COMMENT_LENGTH + 1, CHAMP_MAX_SIZE + 1};

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

unsigned reverse_magic(unsigned magic)
{
	unsigned res = 0;
	unsigned i = 0;

	while (i < 4)
	{
		const unsigned byte = (magic >> 8 * i) & 0xff;
		res |= byte << (24 - 8 * i);
		i++;
	}
	return res;
}
//
//unsigned char reverse(unsigned char b) {
//	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
//	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
//	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
//	return b;
//}


int 	custom_read(int fd, char *buff, size_t size_buff, int check)
{
	int			data;
	unsigned int	magic_key = COREWAR_EXEC_MAGIC;

	data = (int)read(fd, buff, size_buff);
	if (data != -1 && check == 0)
	{
//		int i = -1;
//		while (++i < size_buff)
//		{
//				printf(" ");
//				printf("%.2x", (unsigned char)buff[i]);
//		}
//		write(1, buff, sizeof(buff));
		return (magic_key != reverse_magic((unsigned)buff) ? -1 : data);
//		return (data);
	}
	else if (data != -1 && (check == 1 || check == 2))
		buff[size_buff] = '\0';
	else if (data != -1 && check == 3 && data > CHAMP_MAX_SIZE)
		return (-1);
	return (data);
}
