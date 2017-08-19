/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_fild_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:29:02 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 20:13:13 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_min_fild_width(char **s, t_flag *flags, va_list *arg_p)
{
	int	res;

	while (**s == '*' || ft_isdigit(**s))
	{
		if (**s == '*')
		{
			(*s)++;
			res = va_arg(*arg_p, int);
			if (res < 0)
				flags->f_align = 1;
			flags->width = res < 0 ? -res : res;
			flags->f_width = 1;
		}
		if (ft_isdigit(**s))
		{
			flags->f_width = 1;
			flags->width = 0;
			while (ft_isdigit(**s))
				flags->width = flags->width * 10 + (*(*s)++) - 48;
		}
		ft_flag_char(s, flags);
		ft_precision(s, flags, arg_p, 0);
	}
	return (*s);
}
