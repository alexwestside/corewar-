/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:39:19 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:40:09 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_num_base(uintmax_t num, char *base)
{
	if (num >= ft_strlen(base))
	{
		ft_put_num_base(num / ft_strlen(base), base);
		ft_put_num_base(num % ft_strlen(base), base);
	}
	else
		ft_putchar(base[num]);
}
