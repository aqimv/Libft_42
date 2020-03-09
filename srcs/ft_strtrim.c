/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:36:09 by skennith          #+#    #+#             */
/*   Updated: 2019/09/22 19:36:11 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t'))
		a++;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (i >= a))
		i--;
	if (i == a)
		return (ft_strnew(1));
	return (ft_strsub(s, a, i - a + 1));
}
