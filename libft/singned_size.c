/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singned_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:43:32 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 12:46:01 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	singned_size(va_list *arg_p, t_flag *flags)
{
	intmax_t num;

	num = va_arg(*arg_p, intmax_t);
	if (flags->f_size == hh)
		num = (signed char)num;
	else if (flags->f_size == h)
		num = (signed short int)num;
	else if (flags->f_size == l)
		num = (long int)num;
	else if (flags->f_size == ll)
		num = (long long int)num;
	else if (flags->f_size == j)
		num = (intmax_t)num;
	else if (flags->f_size == z)
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}
