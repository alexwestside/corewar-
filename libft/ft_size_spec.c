/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:38:08 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 16:52:45 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_size_spec(char **s, t_flag *flags, char flag)
{
	if ((**s == 'l' && *(*s + 1) == 'l') || (**s == 'h' && *(*s + 1) == 'h'))
	{
		(**s == 'l' && *(*s + 1) == 'l') ? flags->f_size = ll : 0;
		(**s == 'h' && *(*s + 1) == 'h') ? flags->f_size = hh : 0;
		*s += 2;
		ft_size_spec(s, flags, flag);
		ft_flag_char(s, flags);
		return (*s);
	}
	else if (**s == 'l' || **s == 'h' || **s == 'j' || **s == 'z' || **s == 't')
	{
		if (flag <= **s)
		{
			flag = **s;
			**s == 'l' ? flags->f_size = l : 0;
			**s == 'h' ? flags->f_size = h : 0;
			**s == 'j' ? flags->f_size = j : 0;
			**s == 'z' ? flags->f_size = z : 0;
			**s == 't' ? flags->f_size = t : 0;
		}
		(*s)++;
	}
	ft_check(s, flags, flag);
	return (*s);
}
