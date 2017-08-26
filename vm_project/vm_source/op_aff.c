/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:44:26 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:44:53 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_aff(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	(void)args;
	(void)vm;
	if (vm->flags.flag == 'a')
		ft_printf("Aff: %c\n", fork->reg[args[0] - 1] % 256);
}
