/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:27:23 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 21:30:21 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_wstring(va_list *arg_p, t_flag *flags)
{
	ssize_t	res;
	wchar_t	*str;
	size_t	strlen;
	char	width_padd;

	str = va_arg(*arg_p, wchar_t*);
	if (!str || *str == L'(')
		str = (wchar_t *)"(null)";
	if (flags->f_prec)
		strlen = ft_strnlen((char *)str, flags->prec);
	if (!flags->f_prec)
		strlen = ft_strlen((const char *)str);
	width_padd = (char)(flags->f_zero ? '0' : ' ');
	if (flags->f_width && !flags->f_align)
		ft_width_padd(strlen, flags->width, width_padd);
	ft_putnstr((const char *)str, strlen);
	if (flags->f_width && flags->f_align)
		ft_width_padd(strlen, flags->width, ' ');
	res = flags->f_width ? ft_max(flags->width, strlen) : strlen;
	return (res);
}
