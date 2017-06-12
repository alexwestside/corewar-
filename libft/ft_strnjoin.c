/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:56:39 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:58:35 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	s3 = ft_strncat(s3, s2, len);
	return (s3);
}
