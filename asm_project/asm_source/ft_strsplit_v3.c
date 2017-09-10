/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:57:32 by maksenov          #+#    #+#             */
/*   Updated: 2017/08/26 16:57:33 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_valid.h"

size_t		ft_len_char_3args(char const *s, char c1, char c2, char c3)
{
	char	*p;

	if (!*s)
		return (0);
	while ((*s == c1 || *s == c2 || *s == c3) && *s)
		s++;
	p = (char *)s;
	while ((*p != c1 && *p != c2 && *p != c3) && *p)
		p++;
	return (p - s);
}

int			ft_count_words_3args(char const *s, char c1, char c2, char c3)
{
	char	*p;
	int		cw;

	cw = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while ((*s == c1 || *s == c2 || *s == c3) && *s)
			s++;
		p = (char *)s;
		while ((*p != c1 && *p != c2 && *p != c3) && *p)
			p++;
		((*s != c1 && *s != c2 && *s != c3) && *s) ? cw++ : 0;
		s = p;
	}
	return (cw);
}

char		**ft_strsplit_3args(char const *s, char c1, char c2, char c3)
{
	char	**res;
	char	*p1;
	char	**p2;

	if (!s || !(res = malloc(sizeof(char*) *
	(ft_count_words_3args(s, c1, c2, c3) + 1))))
		return (NULL);
	p2 = res;
	while (*s)
	{
		while ((*s == c1 || *s == c2 || *s == c3) && *s && s++)
			;
		if (*s)
		{
			if (!(p1 = malloc(ft_len_char_3args(s, c1, c2, c3) + 1)))
				return (NULL);
			*res = p1;
			while ((*s != c1 && *s != c2 && *s != c3) && *s && (*p1++ = *s++))
				;
			*p1 = '\0';
			res++;
		}
	}
	*res = NULL;
	return (p2);
}