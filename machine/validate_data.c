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


int		check_machine_key(char *data_read)
{
	if (!ft_memcmp(COREWAR_EXEC_MAGIC, data_read, sizeof(COREWAR_EXEC_MAGIC)))
		return (0);
	return (1);
}

int		check_count_players(int count_strs, char **strs)
{
	unsigned	count;
	int			fd;

	count = 0;
	if (count_strs == 0 || strs == NULL)
		return (2);
	while (--count_strs != -1)
	{
		fd = open(strs[count_strs], O_RONLY);
		count += fd == -1 ? 1 : 0;
	}
	return (count <= MAX_PLAYERS ? 0 : 1);
}