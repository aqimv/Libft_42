/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:56:40 by skennith          #+#    #+#             */
/*   Updated: 2019/09/22 21:56:42 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ch;

	if (len > (len + 1))
		return (NULL);
	ch = (char *)malloc(len + 1);
	if (!s || !ch)
		return (NULL);
	ft_strncpy(ch, &s[start], len);
	ch[len] = '\0';
	return (ch);
}
