/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:41:33 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/15 22:41:41 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

t_query		*create_task(t_fork *fork, int cycle_op, unsigned cycle_now)
{
	t_query *p;

	p = (t_query*)malloc(sizeof(t_query));
	if (p == NULL || fork == NULL)
	{
		free(p);
		return (NULL);
	}
	p->p_fork = fork;
	p->time_cycle = cycle_now + cycle_op;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}

void 		push(t_machine *vm, t_tasks *new_task)
{
	t_tasks *p_top;
	t_tasks *p_bottom;

	p_top = vm->top;
	p_bottom = vm->bottom;
	if (p->bottom && p_bottom->time_cycle > new_task->time_cycle)
	{
		// todo add buttom
		return ;
	}
	if (p->top && p_top->time_cycle > new_task->time_cycle)
	{
		// todo add top
		return ;
	}
	while (p->top && p->bottom && (p->top->time_cycle > new_task->time_cycle || p_bottom->time_cycle < ))
}