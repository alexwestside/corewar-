/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:53:19 by orizhiy           #+#    #+#             */
/*   Updated: 2017/02/09 16:56:05 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *sorc, size_t n)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	dup = ft_strncpy(dup, sorc, n);
	dup[n] = '\0';
	return (dup);
}
