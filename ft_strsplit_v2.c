#include "corewar.h"

int		ft_len_char_2args(char const *s, char c1, char c2)
{
	char *p;

	if (!*s)
		return (0);
	while ((*s == c1 || *s == c2) && *s)
		s++;
	p = (char *)s;
	while ((*p != c1 && *p != c2) && *p)
		p++;
	return (p - s);
}

int		ft_count_words_2args(char const *s, char c1, char c2)
{
	char	*p;
	int		cw;

	cw = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while ((*s == c1 || *s == c2) && *s)
			s++;
		p = (char *)s;
		while ((*p != c1 && *p != c2) && *p)
			p++;
		((*s != c1 && *s != c2) && *s) ? cw++ : 0;
		s = p;
	}
	return (cw);
}

char		**ft_strsplit_2args(char const *s, char c1, char c2)
{
	char	**res;
	char	*p1;
	char	**p2;

	if (!s || !(res = malloc(sizeof(char*) * (ft_count_words_2args(s, c1, c2) + 1))))
		return (NULL);
	p2 = res;
	while (*s)
	{
		while ((*s == c1 || *s == c2) && *s && s++)
			;
		if (*s)
		{
			if (!(p1 = malloc(ft_len_char_2args(s, c1, c2) + 1)))
				return (NULL);
			*res = p1;
			while ((*s != c1 && *s != c2)&& *s && (*p1++ = *s++))
				;
			*p1 = '\0';
			res++;
		}
	}
	*res = NULL;
	return (p2);
}
