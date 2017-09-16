#include "dasm.h"

int 			count_char(char *str)
{
	int i;

	i = 0;
	if (str && *str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

unsigned long long 			ft_expon(unsigned long long base, int n)
{
	unsigned long long nb;

	nb = base;
	if (n == 0)
		return (1);
	while (n > 1)
	{
		base *= nb;
		n--;
	}
	return (base);
}

unsigned long long	ft_itoa_hex(char *str) {
	unsigned long long nb;
	int size;

	nb = 0;
	size = count_char(str);
	if (str) {
		if (!ft_strcmp(str, "00") )//|| *str == 48 || *str == 49)
			return (32);
		while (*str) {
			size--;
			if (*str <= 57 && *str >= 48)
				nb += (ft_expon(16, size) * (*str - 48));
			else if (*str <= 122 && *str >= 97)
				nb += (ft_expon(16, size) * (*str - 87));
			else if (*str <= 90 && *str >= 65)
				nb += (ft_expon(16, size) * (*str - 55));
			str++;
		}
	}
	return (nb);
}

void	magic_n(char **str)
{
	int size = 4;

	while (size-- > 0)
	{
		while (**str != ' ')
			(*str)++;
		(*str)++;
	}
}

char 		*take_name(char ***a)
{
	char 	*name;
	size_t 	length_name;
	int 	i;
	char 	**new;
	char 	*str;

	length_name = sizeof(char) * PROG_NAME_LENGTH + 1 + sizeof(unsigned int) - sizeof(char);
	i = -1;
	name = (char *)malloc(length_name);
	while (++i < length_name)
	{
		name[i] = (char)ft_itoa_hex(**a);
		(*a)++;
	}
	name[i] = '\0';
	new = ft_strsplit(name, ' ');
	i = -1;
	str = "";
	while (new[++i])
	{
		str = ft_strjoin(str, new[i]);
		if (new[i + 1] != NULL)
			str = ft_strjoin(str, " ");
	}
	return (str);
}

char 		*take_comment(char ***a)
{
	char 	*comment;
	size_t 	length_comment;
	int 	i;
	char 	**new;
	char 	*str;

	length_comment = sizeof(char) * COMMENT_LENGTH + 1 + sizeof(unsigned int) - sizeof(char);
	i = -1;
	comment = (char *)malloc(length_comment);
	while (++i < length_comment)
	{
		comment[i] = (char)ft_itoa_hex(**a);
		(*a)++;
	}
	comment[i] = '\0';
	new = ft_strsplit(comment, ' ');
	i = -1;
	str = "";
	while (new[++i])
	{
		str = ft_strjoin(str, new[i]);
		if (new[i + 1] != NULL)
			str = ft_strjoin(str, " ");
	}
	return (str);
}

char 		*hexdump(FILE *fd)
{
	char 	*hex;
	char 	str[1];
	char 	buff[50];
	int 	i;

	hex = "";
	while (fread(str, 1, 1, fd))
	{
		i = sprintf(buff, "%.2x ", *str);
		hex = ft_strnjoin(hex, buff, (size_t)i);
	}
	return (hex);
}

size_t		count_bit(FILE **fd_cor, char *fp)
{
	size_t	i;
	char 	buff[1];

	i = 0;
	while (fread(buff, 1, 1, *fd_cor))
		i++;
	fclose(*fd_cor);
	*fd_cor = fopen(fp, "r");
	return (i);
}

char 		*take_name_op(char *str, int *cod, int *opcode)
{
	int 	i;

	i = (int) ft_itoa_hex(str);
	*opcode = i - 1;
	*cod = op_tab[*opcode].cod_octal;
	return (i <= 16 ? op_tab[*opcode].command_name : NULL);
}

void		add_command_name(t_command **command, char ***a)
{
	char 	*str;
	t_command	*tmp;
	t_command	*head;

	tmp = (t_command *)malloc(sizeof(t_command));
	str = take_name_op(**a, &tmp->cod_octal, &tmp->opcode);
	tmp->command_name = str;
	tmp->next = NULL;
	(*a)++;
	if (!(*command))
		*command = tmp;
	else
	{
		head = *command;
		while ((*command)->next != NULL)
			*command = (*command)->next;
		(*command)->next = tmp;
		*command = head;
	}
}

void		add_command_size(t_command **command, char ***a)
{
	unsigned int	size;

	size = (unsigned int)ft_itoa_hex(**a);
	(*a)++;
	(*command)->size = size;
}

void		take_first_arg(t_command **command, char ***a)
{
	if (!op_tab[(*command)->opcode].args[0][1] && !op_tab[(*command)->opcode].args[0][2])
	{
		if (op_tab[(*command)->opcode].args[0][0] == T_REG)
		{
			(*command)->args[0] = "r";
			(*command)->args[0] = ft_strjoin((*command)->args[0], ft_strsplit(**a, '0')[0]);
			(*a)++;
		}
		else if (op_tab[(*command)->opcode].args[0][0] == T_DIR)
			;
		else if (op_tab[(*command)->opcode].args[0][0] == T_IND)
			;
	}

}

void		add_command_args(t_command **command, char ***a)
{
	take_first_arg(command, a);
}

void		take_all(char **a, size_t size, t_command *command, int fd)
{
	while (a && *a)
	{
		add_command_name(&command, &a);
		add_command_size(&command, &a);
		add_command_args(&command, &a);
		a++;
	}
}

void		byte_pass(char ***a, int i)
{
	while (i-- > 0)
		(*a)++;
}

void		create_file_name(char **a, size_t size, t_command *command)
{
	int 	fd;
	char 	*name;
	char	*str;

	name = take_name(&a);
	fd = open(ft_strjoin(name, ".s"), O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	str = ft_strjoin(ft_strjoin(".name\t\t", ft_strjoin("\"", ft_strjoin(name, "\""))), "\n");
	write(fd, str, ft_strlen(str));
	byte_pass(&a, sizeof(unsigned int));
	str = ft_strjoin(ft_strjoin(".comment\t", ft_strjoin("\"", ft_strjoin(take_comment(&a), "\""))), "\n\n");
	write(fd, str, ft_strlen(str));
	take_all(a, size, command, fd);
	close(fd);
}

void		read_file(FILE *fd_cor, char *fp, t_command *command)
{
	size_t	size;
	size_t	length;
	char 	**a;
	char 	*str;

	size = count_bit(&fd_cor, fp);
	str = hexdump(fd_cor);
	length = sizeof(COREWAR_EXEC_MAGIC) + (sizeof(char) * PROG_NAME_LENGTH + 1 + sizeof(unsigned int) - sizeof(char)) + (sizeof(char) * COMMENT_LENGTH + 1 + sizeof(unsigned int) - sizeof(char)) + sizeof(unsigned int); //prog_size
	a = ft_strsplit(str, ' ');
	byte_pass(&a, sizeof(COREWAR_EXEC_MAGIC));
	create_file_name(a, size - length, command);
//	str = (char *)malloc(sizeof(char) * (size - length + 1));
//	size1 = fread(str, sizeof(char), size - length, fd_cor);
//	str[size - length] = '\0';
//	s = hexdump(str, (int)(size1));
}

int 	main(int ac, char **av)
{
	FILE *fd_cor;
	t_command	*command;
	char 	buff[1];

	command = NULL;
//	ft_printf("%s%s", ft_strjoin(BLUE, ft_strjoin("Are you sure that your file is correct?\nIf YES press -- 1, if not -- 0.\nIf the file is not correct ", END)), ft_strjoin(RED, ft_strjoin("YOU ARE RESPONSIBLE FOR THE RESULT\n", END)));
//	if (read(0, buff, 1) == 1)
//		if (buff[0] != '1')
//			exit(0);
	char *fp = "/nfs/2016/m/maksenov/CLionProjects/new_dasm/zor.cor";
	fd_cor = fopen(fp, "r");
	read_file(fd_cor, fp, command);
	fclose(fd_cor);
	return 0;
}
