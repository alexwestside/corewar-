/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsingned_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:46:19 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 12:48:36 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	unsingned_size(va_list *arg_p, t_flag *flags)
{
	uintmax_t num;

	num = va_arg(*arg_p, intmax_t);
	if (flags->f_size == hh)
		num = (unsigned char)num;
	else if (flags->f_size == h)
		num = (unsigned short int)num;
	else if (flags->f_size == l)
		num = (unsigned long int)num;
	else if (flags->f_size == ll)
		num = (unsigned long long int)num;
	else if (flags->f_size == j)
		num = (uintmax_t)num;
	else if (flags->f_size == z)
		num = (size_t)num;
	else
		num = (unsigned int)num;
	return (num);
}
