/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_padd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:15:12 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:38:49 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_padd(size_t num_len, unsigned int width, char width_padd)
{
	while (num_len < width)
	{
		ft_putchar(width_padd);
		num_len++;
	}
}
