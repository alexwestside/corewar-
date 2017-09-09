/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:36:09 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:44:01 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_add(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	(void)vm;
	fork->reg[args[2] - 1] = fork->reg[args[0] - 1] + fork->reg[args[1] - 1];
}
