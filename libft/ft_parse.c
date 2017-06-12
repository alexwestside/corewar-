/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:48:49 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 20:12:19 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_parse(char **f, va_list *arg_p, t_flag *flags)
{
	ssize_t	res;
	char	flag;

	res = 0;
	if (*(*f)++ == '\0')
		return (res);
	ft_flag_char(f, flags);
	ft_min_fild_width(f, flags, arg_p);
	ft_precision(f, flags, arg_p, 0);
	flag = **f;
	ft_size_spec(f, flags, flag);
	if (!**f)
		return (0);
	res = ft_print_format(f, arg_p, flags);
	(*f)++;
	return (int)(res);
}
