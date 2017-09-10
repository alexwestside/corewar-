/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hexadesimalxl.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:33:18 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 18:21:33 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_unsigned_hexadesimalxl(va_list *arg_p, t_flag *flags)
{
	uintmax_t	num;
	ssize_t		res;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, HEXL_BASE, "0X");
	return (res);
}
