/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:05:11 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 20:13:53 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision(char **s, t_flag *flags, va_list *arg_p, int res)
{
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			res = va_arg(*arg_p, int);
			if (res >= 0)
			{
				flags->f_prec = 1;
				flags->prec = res;
			}
			return (++(*s));
		}
		else
		{
			while (ft_isdigit(**s))
				flags->prec = flags->prec * 10 + (*(*s)++) - 48;
			flags->f_prec = 1;
			**s == '.' && !ft_isdigit(**s) ? flags->prec = 0 : 0;
			ft_precision(s, flags, arg_p, 0);
			ft_flag_char(s, flags);
			return (*s);
		}
	}
	return (*s);
}
