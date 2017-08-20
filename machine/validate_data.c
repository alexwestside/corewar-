/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:06:07 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 23:06:11 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

int		check_read_data(t_machine *vm, int index_player, char *file)
{
	int			er_s;
	static char err[] = "ERROR:";

	er_s = 0;
	if (vm->players[index_player].magic != COREWAR_EXEC_MAGIC)
		er_s = ft_printf("%s File %s has an an invalid header\n", err, file);
	er_s != 0 ? error_exit("\0", 777, vm) : 0;
	if (vm->players[index_player].prog_size > CHAMP_MAX_SIZE)
		er_s = ft_printf("%s File %s has too large a code "
		"(%u bytes > %u bytes)\n", err, file,
		vm->players[index_player].prog_size, CHAMP_MAX_SIZE);
	er_s != 0 ? error_exit("\0", 777, vm) : 0;
	return (0);
}

void	check_is_champion(t_machine *vm, int fd, char *file_name)
{
	size_t	sum;
	ssize_t	rd;
	char	buff[SIZE_BUFF];

	sum = 0;
	while ((rd = read(fd, buff, SIZE_BUFF)) > 0)
		sum += rd;
	lseek(fd, 0, SEEK_SET);
	if (sum < sizeof(header_t))
		error_exit(file_name, 1, vm);
}
