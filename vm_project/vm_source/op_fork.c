/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:45 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:54 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

void	op_fork(int args[MAX_ARGS_NUMBER], t_fork *fork, t_machine *vm)
{
	t_fork *tmp;

	tmp = create_fork(0, 0);
	add_before(&vm->head_lst, tmp);
	inheritance(tmp, fork, args[0] % IDX_MOD);
	vm->count_forks++;
}
