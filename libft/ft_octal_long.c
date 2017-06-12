/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:07:44 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 21:09:44 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_octal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t res;

	flags->f_size = l;
	res = ft_octal(arg_p, flags);
	return (res);
}
