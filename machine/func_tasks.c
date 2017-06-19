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

void 		add_top(t_tasks **top, t_tasks **bottom, t_tasks *new_task)
{
	if (*top == NULL || *bottom == NULL)
	{
		*top = new_task;
		*bottom = new_task;
		return ;
	}
	*top->prev = new_task;
	new_task->next = *top->p_fork;
	*top->p_fork = new_task;
}

void 		add_bottom(t_tasks **top, t_tasks **bottom, t_tasks *new_task)
{
	if (*top == NULL || *bottom == NULL)
	{
		*top = new_task;
		*bottom = new_task;
		return ;
	}
	*bottom->next = new_task;
	new_task->prev = *bottom->p_fork;
	*bottom->p_fork = new_task;
}

int			push_before(t_tasks **iter_node, t_tasks *new_task)
{
	t_tasks *p;

	p = *iter_node;
	new_task->next = p->next;
	new_task->prev = p;
	p->next = new_task;
	return (0);
}

void 		push(t_tasks **top, t_tasks **bottom, t_tasks *new_task)
{
	t_tasks *p_top;
	t_tasks *p_bottom;
	int		f;

	p_top = *top;
	p_bottom = *bottom;
	f = 1;
	if (p_top == NULL || p_bottom == NULL)
		add_bottom(top, bottom, new_task);
	else if (p_bottom && p_bottom->time_cycle > new_task->time_cycle)
		add_bottom(top, bottom, new_task);
	else if (p->top && p_top->time_cycle < new_task->time_cycle)
		add_top(top, bottom, new_task);
	else
		while (p_top != p_bottom && f)
		{
			if (p_top->time_cycle > new_task->time_cycle)
				f = push_before(p_top, new_task);
			else if (p_bottom->time_cycle <= new_task->time_cycle)
				f = push_before(p_bottom, new_task);
			p_top = p_top->next;
			p_bottom = p_bottom->prev;
		}
}

t_tasks		*pop(t_tasks **bottom)
{
	t_tasks *p_bottom;

	p_bottom = *bottom;
	if (p_bottom == NULL)
		return (NULL);
	*bottom = p_bottom->prev;
	*bottom->next = NULL;
	return (p_bottom);
}
