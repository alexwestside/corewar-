/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:36:07 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 16:00:48 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_octal(va_list *arg_p, t_flag *flags)
{
	uintmax_t		num;
	char			width_padd;
	unsigned int	num_len;

	num = unsingned_size(arg_p, flags);
	num_len = ft_num_len(num, flags, OCT_BASE);
	if (flags->f_alter && !num && !flags->prec)
	{
		if (flags->f_width && !flags->f_alter)
		{
			width_padd = (char)(flags->f_zero ? '0' : ' ');
			ft_width_padd(1, flags->width, width_padd);
		}
		ft_putchar('0');
		if (flags->f_width && flags->f_align)
			ft_width_padd(1, flags->width, ' ');
		return (flags->width ? ft_max(flags->width, 1) : 1);
	}
	else if (flags->f_alter && num)
	{
		flags->f_prec = 1;
		flags->prec = ft_max(flags->prec, num_len + 1);
	}
	return (ft_unsigned(num, flags, OCT_BASE, NULL));
}
