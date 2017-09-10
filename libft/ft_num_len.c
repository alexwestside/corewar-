/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:42 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:12:08 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_num_len(uintmax_t num, t_flag *flags, char *base)
{
	ssize_t			base_len;
	unsigned int	i;

	(void)flags;
	i = 0;
	base_len = ft_strlen(base);
	if (!num)
		return (1);
	while (num)
	{
		num = num / base_len;
		i++;
	}
	return (i);
}
