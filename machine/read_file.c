
#include "machine.h"

void 	multi_parsing_files(t_machine *vm, char **path_files)
{
	int	i;
	int	fd;

	i = -1;
	if (path_files == NULL)
		error_exit("something is wrong", 0, vm);
	while (path_files[++i])
	{
		if ((fd = open(path_files[i], O_RDONLY)) == -1)
			error_exit(path_files[i], -1, vm);
		check_is_champion(vm, fd, path_files[i]);
		read_data(vm, fd, i);
		check_corect_data_read(vm, i, path_files[i]);
		read_code_player(vm, fd, i, path_files[i]) == -1 ?
		error_exit("something is wrong to read file champion", 0, vm) : 0;
		close(fd);
	}
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
	ssize_t 	rd;
	static size_t st[] = {sizeof(COREWAR_EXEC_MAGIC), PROG_NAME_LENGTH, 4,
						  sizeof(vm->players[i].prog_size), COMMENT_LENGTH, 4};
	static	int size_st = 6;

	j = -1;
	rd = 0;
	while (++j < size_st && rd != -1)
	{
		buf = (char *)malloc(st[j]);
		if (!buf || ((rd = read(fd, buf, st[j])) == -1))
			break ;
		j == 0 ? vm->players[i].magic = *(unsigned*)reverse(buf, st[j]) : 0;
		j == 1 ? ft_memcpy(vm->players[i].prog_name, buf, (size_t)rd) : 0;
		(j == 2 || j == 5) && rd != (ssize_t)st[j] ? rd = -1 : 0;
		j == 3 ? vm->players[i].prog_size = *(unsigned*)reverse(buf, st[j]) : 0;
		j == 4 ? ft_memcpy(vm->players[i].comment, buf, (size_t)rd) : 0;
		free(buf);
	}
	return (0);
}

int		read_code_player(t_machine *vm, int fd, int index, char *file_name)
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
	vm->players[index].code = (unsigned char *)malloc(sum * sizeof(unsigned char));
	ft_memcpy(vm->players[index].code, tmp, sum);
	free(tmp);
	vm->players[index].prog_size != sum ? error_exit(file_name, 6, vm) : 0;
	return (sum > 0 ? (int)sum : -1);
}
