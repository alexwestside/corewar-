/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharacter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:28:22 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 20:30:36 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_wcharacter(va_list *arg_p, t_flag *flags)
{
	ssize_t			res;
	wchar_t			c;
	unsigned int	char_len;
	char			width_padd;

	c = (wchar_t)va_arg(*arg_p, wint_t);
	char_len = ft_wcharlen(c);
	width_padd = (char)(flags->f_zero ? '0' : ' ');
	if (flags->f_width && !flags->f_align)
		ft_width_padd(char_len, flags->width, width_padd);
	ft_putchar(c);
	if (flags->f_width && flags->f_align)
		ft_width_padd(char_len, flags->width, width_padd);
	res = flags->f_width ? ft_max(char_len, flags->width) : char_len;
	return (res);
}
