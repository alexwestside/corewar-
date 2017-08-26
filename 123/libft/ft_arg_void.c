/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:09:56 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 18:19:52 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_arg_void(va_list *arg_p, t_flag *flags)
{
	ssize_t		res;
	uintmax_t	num;

	flags->f_size = z;
	if (flags->f_prec)
		flags->f_zero = 0;
	num = unsingned_size(arg_p, flags);
	res = ft_signed(num, flags, HEX_BASE, "0x");
	return (res);
}
