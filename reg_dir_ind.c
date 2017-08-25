
#include "asm.h"

void	type_command(t_bot bot, t_command *command, int fd)
{
	int		i;
	char	*command_name;

	i = -1;
	if (!command->command_name)
		command_name = get_command_name(bot.hash_table,
		bot.keys, command->method);
	else
		command_name = command->command_name;
	while (++i < REG_NUMBER)
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break ;
	write(fd, &op_tab[i].opcode, sizeof(char));
}

void	get_code_byte(t_command *h_command, int fd)
{
	int	code_byte;
	int	i;

	i = -1;
	code_byte = 0;
	while (++i < h_command->count_args)
	{
		if (h_command->arg[i].arg_type == T_REG)
			code_byte += REG_CODE << (6 - (i != 2 ? i * 2 : 4));
		if (h_command->arg[i].arg_type == T_DIR)
			code_byte += DIR_CODE << (6 - (i != 2 ? i * 2 : 4));
		if (h_command->arg[i].arg_type == T_IND)
			code_byte += IND_CODE << (6 - (i != 2 ? i * 2 : 4));
	}
	write(fd, &code_byte, sizeof(char));
}

void	t_ind_to_byte(char *command_data, int fd)
{
	size_t	size;
	int		num;

	size = IND_SIZE;
	num = ft_atoi(command_data);
	swap_bytes((char *)&num, IND_SIZE);
	write(fd, &num, size);
}

void	t_dir_to_byte(char **data, int fd, t_corewar *corewar, int current_line)
{
	int		distance;
	size_t	dist_to_command;
	size_t	dist_to_method;
	size_t	size;
	int		dir_num;

	size = get_t_dir_size(data[0]);
	if (ft_strchr(data[1], ':'))
	{
		data[2] = ft_strndup((ft_strchr(data[1], LABEL_CHAR) + 1),
		ft_strlen(data[1]) - 2);
		dist_to_command =
get_distance_to_command(corewar, current_line, 0, corewar->bot.command);
		dist_to_method = get_distance_to_method(data[2], corewar, 0, NULL);
		distance = (int)(dist_to_method - dist_to_command);
		swap_bytes((char *)&distance, size);
		write(fd, &distance, size);
		return ;
	}
	dir_num = ft_atoi(ft_strsplit(data[1], '%')[0]);
	swap_bytes((char *)&dir_num, size);
	write(fd, &dir_num, size);
}

void	t_reg_to_byte(char *command_data, int fd)
{
	size_t	size;
	int		num_reg;

	size = 1;
	num_reg = ft_atoi(ft_strsplit(command_data, 'r')[0]);
	write(fd, &num_reg, size);
}
