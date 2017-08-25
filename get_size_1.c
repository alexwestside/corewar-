
#include "asm.h"

void	get_prog_size(header_t *header, t_corewar *corewar,
int fd, t_command *command)
{
	t_command		*h_command;

	while (command)
	{
		if (!command->command_name)
		{
			h_command = get_table(corewar->bot.hash_table,
corewar->bot.keys, command->method)->command;
			while (h_command)
			{
				if (!h_command->command_name)
					break ;
				gps_1(header, &h_command);
			}
		}
		else
		{
			if (!command->command_name)
				break ;
			gps_2(header, command);
		}
		command = command->next;
	}
	swap_bytes((char *)&header->prog_size, sizeof(header->prog_size));
	write(fd, &header->prog_size, sizeof(header->prog_size));
}

void	gps_2(header_t *header, t_command *command)
{
	header->prog_size++;
	if (command->count_args > 1 && ft_strcmp(command->command_name, "aff"))
		header->prog_size++;
	header->prog_size += get_size_args(command);
}

void	gps_1(header_t *header, t_command **h_command)
{
	header->prog_size++;
	if ((*h_command)->count_args > 1 &&
		ft_strcmp((*h_command)->command_name, "aff"))
		header->prog_size++;
	header->prog_size += get_size_args(*h_command);
	*h_command = (*h_command)->next;
}
