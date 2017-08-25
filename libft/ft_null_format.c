/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:36:58 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 21:39:09 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_null_format(char **format, va_list *arg_p, t_flag *flags)
{
	char	width_padd;
	ssize_t	res;

	(void)arg_p;
	width_padd = (char)(flags->f_zero ? '0' : ' ');
	if (flags->f_width && !flags->f_align)
		ft_width_padd(1, flags->width, width_padd);
	ft_putchar(**format);
	if (flags->f_width && flags->f_align)
		ft_width_padd(1, flags->width, ' ');
	res = flags->f_width ? ft_max(flags->width, 1) : 1;
	return (res);
}
