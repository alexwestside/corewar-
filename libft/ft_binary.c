/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:53:01 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 19:55:23 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_binary(va_list *arg_p, t_flag *flags)
{
	ssize_t		res;
	uintmax_t	num;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, BIN_BASE, "0b");
	return (res);
}
