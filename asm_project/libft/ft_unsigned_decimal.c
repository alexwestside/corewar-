/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:37:22 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 16:16:45 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_unsigned_decimal(va_list *arg_p, t_flag *flags)
{
	ssize_t		res;
	uintmax_t	num;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, DEC_BASE, NULL);
	return (res);
}
