/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:30:33 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 16:14:29 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_string(va_list *arg_p, t_flag *flags)
{
	ssize_t	res;
	size_t	strlen;
	char	*str;
	char	width_padd;

	if (flags->f_size == l)
		return (ft_wstring(arg_p, flags));
	else
	{
		str = va_arg(*arg_p, char*);
		if (!str)
			str = "(null)";
		if (flags->f_prec)
			strlen = ft_strnlen(str, flags->prec);
		if (!flags->f_prec)
			strlen = ft_strlen(str);
		width_padd = (char)(flags->f_zero ? '0' : ' ');
		if (flags->f_width && !flags->f_align)
			ft_width_padd(strlen, flags->width, width_padd);
		ft_putnstr(str, strlen);
		if (flags->f_width && flags->f_align)
			ft_width_padd(strlen, flags->width, ' ');
		res = flags->f_width ? ft_max(flags->width, strlen) : strlen;
		return (res);
	}
}
