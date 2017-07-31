

#include "machine.h"

t_fork		*create_fork(int id, int pc)
{
	t_fork *new_fork;

	new_fork = (t_fork*)malloc(sizeof(t_fork));
	if (new_fork == NULL)
		return (NULL);
	new_fork->carry = 0;
	new_fork->life = 0;
	new_fork->pc = pc;
	new_fork->id = id;
	new_fork->reg[0] = id;
	new_fork->mod = 0;
	new_fork->cmd = 0;
	new_fork->time_cycle = 0;
	new_fork->next = NULL;
	return (new_fork);
}

void		add_before(t_fork **alst, t_fork *node)
{
	if (*alst)
		node->next = *alst;
	*alst = node;
}