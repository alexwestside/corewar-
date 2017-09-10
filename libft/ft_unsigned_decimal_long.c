/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:35:43 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 19:36:53 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_unsigned_decimal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t		res;
	uintmax_t	num;

	flags->f_size = l;
	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, DEC_BASE, NULL);
	return (res);
}
