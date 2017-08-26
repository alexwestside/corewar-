/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:46:57 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 22:47:03 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../op.h"

typedef struct	s_process
{
	int			carry : 1; 			// carry flag
	size_t		pc;           	 	// position in char elements
	int			reg[REG_NUMBER];	// registers of the processor
}				t_process;

#endif
