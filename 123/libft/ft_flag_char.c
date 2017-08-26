/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:32:03 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/11 14:18:07 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_char(char **s, t_flag *flags)
{
	if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' ||
		**s == 39 || **s == '$' || **s == 'L')
	{
		**s == '#' ? flags->f_alter = 1 : 0;
		**s == '0' ? flags->f_zero = 1 : 0;
		**s == '-' ? flags->f_align = 1 : 0;
		**s == '+' ? flags->f_sing = 1 : 0;
		**s == ' ' ? flags->f_blank = 1 : 0;
		**s == 39 ? flags->f_apostrophe = 1 : 0;
		**s == '$' ? flags->f_rev_arg = 1 : 0;
		**s == 'L' ? flags->f_l = 1 : 0;
		(*s)++;
		flags->f_align ? flags->f_zero = 0 : 0;
		return (ft_flag_char(s, flags));
	}
	return (*s);
}
