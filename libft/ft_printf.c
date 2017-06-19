/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:00:43 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 16:30:35 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg_p;
	size_t	res;

	res = 0;
	va_start(arg_p, format);
	res = ft_finder(format, &arg_p, res);
	va_end(arg_p);
	return (int)(res);
}
