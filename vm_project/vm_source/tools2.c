/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:37:04 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/21 14:37:11 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

unsigned	move_pc(unsigned pc)
{
	unsigned res;

	res = pc % MEM_SIZE;
	return (res);
}

int			is_number(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

void		inheritance(t_fork *child, t_fork *father, int shift)
{
	child->id = father->id;
	child->pc = move_pc(father->pc + shift);
	child->life = father->id;
	child->time_cycle = -1;
	child->cmd = -1;
	child->carry = father->carry;
	ft_memcpy(child->reg, father->reg, sizeof(int) * REG_NUMBER);
}
