/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:52:32 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/10 14:01:31 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_finder(const char *f, va_list *arg_p, size_t res)
{
	char	*p;
	ssize_t	len;
	t_flag	flags;

	p = ft_strchr(f, '%');
	if (*f == '\0')
		return (res);
	if (p > f)
	{
		ft_putnstr(f, (p - f));
		return (ft_finder(p, arg_p, res + (p - f)));
	}
	else if (p == NULL)
	{
		res += ft_strlen(f);
		ft_putstr(f);
		return (res);
	}
	else
	{
		ft_bzero(&flags, sizeof(flags));
		len = ft_parse((char **)&f, arg_p, &flags);
		res = ft_finder(f, arg_p, res + len);
		return (res);
	}
}
