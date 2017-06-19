/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:31:34 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 20:35:42 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_character(va_list *arg_p, t_flag *flags)
{
	char	width_padd;
	ssize_t	res;

	if (flags->f_size == l)
		ft_wcharacter(arg_p, flags);
	else
	{
		if (flags->f_width && !flags->f_align)
		{
			width_padd = (char)(flags->f_zero ? '0' : ' ');
			ft_width_padd(1, flags->width, width_padd);
		}
		ft_putchar(va_arg(*arg_p, int));
		if (flags->f_width && flags->f_align)
			ft_width_padd(1, flags->width, ' ');
	}
	res = flags->f_width ? ft_max(flags->width, 1) : 1;
	return (res);
}
