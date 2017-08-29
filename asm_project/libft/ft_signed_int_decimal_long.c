/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_int_decimal_long.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:08:44 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 21:09:25 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_signed_int_decimal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t res;

	flags->f_size = l;
	res = ft_signed_int_decimal(arg_p, flags);
	return (res);
}
