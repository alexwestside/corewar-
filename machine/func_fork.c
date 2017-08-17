

#include "machine.h"

t_fork		*create_fork(int id, int pc)
{
    int i;
	t_fork *new_fork;

    i = 0;
	new_fork = (t_fork*)malloc(sizeof(t_fork));
	if (new_fork == NULL)
		return (NULL);
	new_fork->carry = 0;
	new_fork->life = 0;
	new_fork->pc = pc;
	new_fork->id = id;
    while (++i < REG_NUMBER)
        new_fork->reg[i] = 0;
	new_fork->reg[0] = id;
	new_fork->mod = 0;
	new_fork->cmd = -1;
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

void       all_delete(t_fork **alst)
{
	t_fork *iter;
    t_fork *del;

    iter = *alst;
	while (iter)
	{
		del = iter;
		iter = iter->next;
		free(del);
	}
}

void	delete_forks(t_machine *vm, t_fork *oldfork)
{
	t_fork *q;

	q = vm->head_lst;
	if (vm->head_lst == oldfork)
		vm->head_lst = oldfork->next;
	else
	{
		while (q && q->next != oldfork)
			q = q->next;
		if (q == NULL)
			return ;
		q->next = oldfork->next;
	}
	free(oldfork);
}
