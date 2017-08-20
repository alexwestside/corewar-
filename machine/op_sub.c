/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:00:32 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 17:00:34 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_sub(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	(void)vm;
	fork->reg[args[2] - 1] = fork->reg[args[0] - 1] - fork->reg[args[1] - 1];
}
