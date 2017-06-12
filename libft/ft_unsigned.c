/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:10:16 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 19:21:36 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_unsigned(uintmax_t num, t_flag *flags, char *base, char *prefix)
{
	unsigned int	n;
	unsigned int	s;
	ssize_t			res;

	flags->f_prec ? flags->f_zero = 0 : 0;
	n = ft_num_len(num, flags, base);
	if (flags->f_width && !flags->f_align && flags->f_zero)
	{
		flags->prec = ft_max(flags->width, flags->f_prec ? flags->prec : n);
		flags->f_prec = 1;
		flags->f_width = 0;
	}
	s = ft_num_strlen(num, base, prefix, flags);
	flags->f_width && !flags->f_align ? ft_width_padd(s, flags->width, ' ') : 0;
	if (flags->f_alter && prefix && num)
	{
		ft_putstr(prefix);
		flags->f_zero ? s -= 2 : 0;
		flags->f_zero ? flags->prec -= 2 : 0;
	}
	ft_num_width(num, base, n, flags);
	flags->f_width && flags->f_align ? ft_width_padd(s, flags->width, ' ') : 0;
	res = flags->f_width ? ft_max(s, flags->width) : s;
	return (res);
}
