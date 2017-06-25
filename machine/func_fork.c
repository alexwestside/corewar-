

#include "machine.h"

t_fork	*create_fork(int id, int pc)
{
	t_fork *new_fork;

	new_fork = (t_fork*)malloc(sizeof(t_fork));
	if (new_fork == NULL)
		return (NULL);
	new_fork = (t_fork){0, 0, pc, id};
	new_fork->reg[0] = id;
	return (new_fork);
}
