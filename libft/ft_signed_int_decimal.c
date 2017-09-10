/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_int_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:24:01 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 19:29:39 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_signed_int_decimal(va_list *arg_p, t_flag *flags)
{
	intmax_t	num;
	char		*prefix;
	ssize_t		res;

	prefix = NULL;
	num = singned_size(arg_p, flags);
	if (num < 0 || flags->f_blank || flags->f_sing)
	{
		if (num < 0)
		{
			num = -num;
			prefix = "-";
		}
		else if (flags->f_sing)
			prefix = "+";
		else if (flags->f_blank)
			prefix = " ";
		res = ft_signed(num, flags, DEC_BASE, prefix);
	}
	else
		res = ft_unsigned((uintmax_t)num, flags, DEC_BASE, NULL);
	return (res);
}
