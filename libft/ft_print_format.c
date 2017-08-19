/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:39:20 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 18:19:37 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_print_format(char **f, va_list *arg_p, t_flag *flags)
{
	t_convers_form	arr_convers[300];
	char			*str;

	str = (char *)"sSpdDioOuUxXcCb%";
	arr_convers['s'] = (t_convers_form)&ft_string;
	arr_convers['S'] = (t_convers_form)&ft_wstring;
	arr_convers['p'] = (t_convers_form)&ft_arg_void;
	arr_convers['d'] = (t_convers_form)&ft_signed_int_decimal;
	arr_convers['D'] = (t_convers_form)&ft_signed_int_decimal_long;
	arr_convers['i'] = (t_convers_form)&ft_signed_int_decimal;
	arr_convers['o'] = (t_convers_form)&ft_octal;
	arr_convers['O'] = (t_convers_form)&ft_octal_long;
	arr_convers['u'] = (t_convers_form)&ft_unsigned_decimal;
	arr_convers['U'] = (t_convers_form)&ft_unsigned_decimal_long;
	arr_convers['x'] = (t_convers_form)&ft_unsigned_hexadesimalx;
	arr_convers['X'] = (t_convers_form)&ft_unsigned_hexadesimalxl;
	arr_convers['c'] = (t_convers_form)&ft_character;
	arr_convers['C'] = (t_convers_form)&ft_wcharacter;
	arr_convers['b'] = (t_convers_form)&ft_binary;
	arr_convers['%'] = (t_convers_form)&ft_single_persent;
	if (!ft_strchr((const char *)str, **f))
		return (ft_null_format(f, arg_p, flags));
	else
		return ((arr_convers[(int)**f])(arg_p, flags));
}
