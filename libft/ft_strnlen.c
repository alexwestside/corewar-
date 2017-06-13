/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:59:01 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:59:53 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strnlen(char *str, size_t strlen)
{
	size_t	i;

	i = 0;
	while (*str && strlen--)
	{
		i++;
		str++;
	}
	return (i);
}