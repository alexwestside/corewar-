/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:00:20 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 19:22:35 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_signed(intmax_t num, t_flag *flags, char *base, char *prefix)
{
	size_t	str_len;
	size_t	prefix_len;
	ssize_t	res;

	prefix_len = ft_strlen(prefix);
	str_len = prefix_len + ft_num_strlen(num, base, NULL, flags);
	if (flags->f_width && !flags->f_align && !flags->f_zero)
	{
		ft_width_padd(str_len, flags->width, ' ');
		prefix_len = prefix_len + ft_max((flags->width - str_len), 0);
		flags->f_width = 0;
	}
	else if (flags->f_width)
		flags->width = (unsigned int)(flags->width - prefix_len);
	ft_putstr(prefix);
	res = ft_unsigned((uintmax_t)num, flags, base, NULL);
	return (res + prefix_len);
}
