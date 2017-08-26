/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:49:53 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:51:49 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_num_width(uintmax_t num, char *base,
										unsigned int num_len, t_flag *flags)
{
	if (flags->f_prec)
		ft_width_padd(num_len, flags->prec, '0');
	if (!num && flags->f_prec && !flags->prec)
		return ;
	else
		ft_put_num_base(num, base);
}
