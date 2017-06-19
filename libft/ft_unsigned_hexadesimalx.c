/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hexadesimalx.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:30:00 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 18:21:42 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_unsigned_hexadesimalx(va_list *arg_p, t_flag *flags)
{
	uintmax_t	num;
	ssize_t		res;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, HEX_BASE, "0x");
	return (res);
}
