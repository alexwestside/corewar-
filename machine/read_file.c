
#include "machine.h"

int 	multi_parsing_files(t_machine *vm, char **path_files)
{
	int	i;
	int	fd;
	int	err;

	i = -1;
	fd = 0;
	err = 0;
	if (path_files == NULL)
		return (-1);
	while (path_files[++i])
	{
		if (err == -1 || (fd = open(path_files[i], O_RDONLY)) == -1)
			break ;
		read_data(vm, fd, i);
		read_code_player(vm, fd, i);
		err = check_corect_data_read(*vm, i);
		close(fd);
	}
	return (err == -1 || fd == -1 ? -1 : 0);
}

char	*reverse(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = str[size - i - 1];
		str[size - i - 1] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

int 	read_data(t_machine *vm, int fd, int i)
{
	int		j;
	char 	*buf;
	int 	rd;
	static size_t st[] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH, 4,
						  sizeof(vm->players[i].prog_size), COMMENT_LENGTH, 4};
	static	int size_st = 6;

	j = -1;
	rd = 0;
	while (++j < size_st && rd != -1)
	{
		buf = (char *)malloc(st[j]);
		if (!buf || ((rd = (int)read(fd, buf, st[j])) == -1))
			break ;
		j == 0 ? vm->players[i].magic = *(unsigned*)reverse(buf, st[j]) : 0;
		j == 1 ? ft_memcpy(vm->players[i].prog_name, buf, (size_t)rd) : 0;
		(j == 2 || j == 5) && rd != st[j] ? rd = -1 : 0;
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
	if (vm->code_players == NULL)
		vm->code_players = (unsigned char **)malloc(vm->count_players * sizeof(unsigned char*));
	if (vm->code_players == NULL)
		return (-1);
	vm->code_players[index] = (unsigned char *)malloc(sum * sizeof(unsigned char));
	vm->size_code_players[index] = sum;
	ft_memcpy(vm->code_players[index], tmp, sum);
	free(tmp);
	return (sum > 0 ? (int)sum : -1);
}
