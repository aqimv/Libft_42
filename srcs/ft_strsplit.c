/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:13:34 by skennith          #+#    #+#             */
/*   Updated: 2019/09/25 16:13:36 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_s(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static size_t	sizechr(const char *ch, char c)
{
	size_t i;

	i = 0;
	while (ch[i] && ch[i] != c)
		i++;
	return (i);
}

static void		arrclear(char **ch)
{
	while (*ch)
		free(*ch++);
	free(ch);
}

static char		**splitc(const char *s, char c, size_t count, char **ch)
{
	size_t		size;
	int			x;
	size_t		i;

	x = 0;
	i = 0;
	while (count > 0)
	{
		if (s[i] != c && count--)
		{
			size = sizechr(&s[i], c);
			if (!(ch[x++] = ft_strsub(s, i, size)))
			{
				arrclear(ch);
				return (NULL);
			}
			i += size;
		}
		i++;
	}
	ch[x] = NULL;
	return (ch);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ch;
	size_t		count;

	if (!s || !(ch = malloc((sizeof(char *) * ft_s(s, c)) + 1)))
		return (NULL);
	count = ft_s(s, c);
	if (count > count + 1)
		return (NULL);
	ch = splitc(s, c, count, ch);
	return (ch);
}
