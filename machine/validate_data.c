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


int 	check_corect_data_read(t_machine *vm, int index_player, char *file)
{
	static char err[] = "ERROR:";
	int			er_s;

	er_s = 0;
	if (vm->players[index_player].magic != COREWAR_EXEC_MAGIC)
		er_s = ft_printf("%s File %s has an an invalid header\n", err, file);
//		error_exit("Unvalid magic into player champions", 0, vm);
	er_s != 0 ? error_exit("\0", 777, vm) : 0;
	if (vm->players[index_player].prog_size > CHAMP_MAX_SIZE)
		er_s = ft_printf("%s File %s has too large a code (%u bytes > %u bytes)\n",
						 err, file, vm->players[index_player].prog_size, CHAMP_MAX_SIZE);
//		error_exit("Is too big to be a champion", 0, vm);
	er_s != 0 ? error_exit("\0", 777, vm) : 0;
	return (0);
}


void	check_is_champion(t_machine *vm, int fd, char *file_name)
{
	ssize_t rd;
	char 	buff[SIZE_BUFF];
	size_t 	sum;

	sum = 0;
	while ((rd = read(fd, buff, SIZE_BUFF)) > 0)
		sum += rd;
	lseek(fd, 0, SEEK_SET);
	if (sum < sizeof(header_t))
		error_exit(file_name, 1, vm);
}


//int		check_placement_players(t_machine vm)
//{
//	int i;
//	int size;
//
//	i = -1;
//	size =  MEM_SIZE / vm.count_players;
//	while (++i < vm.count_players)
//		if (vm.players[i].prog_size > size)
//			return (-2);
//	return (0);
//}