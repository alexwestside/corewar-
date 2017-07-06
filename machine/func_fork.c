

#include "machine.h"

t_fork		*create_fork(int id, int pc)
{
	t_fork *new_fork;

	new_fork = (t_fork*)malloc(sizeof(t_fork));
	if (new_fork == NULL)
		return (NULL);
	new_fork = (t_fork){0, 0, pc, id};
	new_fork->reg[0] = id;
	return (new_fork);
}

t_forks		*create_containe(t_fork *node)
{
	t_forks *new_container;

	new_container = (t_forks*)malloc(sizeof(t_forks));
	if (new_container == NULL)
		return (NULL);
	new_container = (t_forks){node, 0, 0, NULL};
	return (new_container);
}


void		add_forks(t_forks **alts, t_fork *node)
{
	t_forks *p;
	t_forks *new;

	new = create_containe(node);
	if (new == NULL)
		return ;
	p = *alts;
	if (p)
		new->next = p->next;
	p = new;
}

void		delete(t_forks **alts, t_forks *node)
{
	t_forks *p;

	p = *alts;
	if (p == node)
	{
		p = node->next;
		free(node);
		return ;
	}
	else
		while (p && p != node)
			p = p->next;
	p != NULL ? p->next = node->next : 0;
	free(node);
}