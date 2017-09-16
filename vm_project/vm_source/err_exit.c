/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:40:20 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 12:40:26 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	error_exit(char *str, int code, t_machine *vm)
{
	if (code == -1)
		ft_printf("Can't read source file %s\n", str);
	else if (code == -5)
		ft_printf("ERROR: Too many champions max are %d\n", MAX_PLAYERS);
	else if (code == 1)
		ft_printf("ERROR: %s is too small to be a champion \n", str);
	else if (code == 6)
		ft_printf("ERROR: File %s has a code size that differ from what "
		"its header says\n", str);
	else if (code == 10)
		ft_printf("ERROR: unrestricted champion number or already a "
						  "champion with that number\n");
	release_memory(vm);
	exit(code);
}
