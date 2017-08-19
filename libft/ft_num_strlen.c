/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:12:30 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:14:43 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_num_strlen(uintmax_t num, char *base,
													char *prefix, t_flag *flags)
{
	unsigned int num_len;
	unsigned int num_strlen;

	num_len = ft_num_len(num, flags, base);
	if (!num && flags->f_prec && !flags->prec)
		num_strlen = 0;
	else if (flags->f_prec)
		num_strlen = ft_max(num_len, flags->prec);
	else
		num_strlen = num_len;
	if (flags->f_alter && prefix && num)
		num_strlen = num_strlen + (unsigned int)ft_strlen(prefix);
	return (num_strlen);
}
