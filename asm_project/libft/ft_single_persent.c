/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_persent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:26:33 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 20:31:18 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_single_persent(va_list *arg_p, t_flag *flags)
{
	char	width_padd;
	ssize_t	res;

	(void)arg_p;
	if (flags->f_width && !flags->f_align)
	{
		width_padd = (char)(flags->f_zero ? '0' : ' ');
		ft_width_padd(1, flags->width, width_padd);
	}
	ft_putchar('%');
	if (flags->f_width && flags->f_align)
		ft_width_padd(1, flags->width, ' ');
	res = flags->f_width ? ft_max(flags->width, 1) : 1;
	return (res);
}
