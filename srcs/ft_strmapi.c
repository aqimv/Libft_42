/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:29:43 by skennith          #+#    #+#             */
/*   Updated: 2019/09/22 18:29:44 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	char	*a;
	int		i;

	if (!s || !f || ft_strlen((char *)s) > (ft_strlen((char *)s) + 1))
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s) + 1);
	a = (char *)s;
	if (!res)
		return (NULL);
	i = 0;
	while (a[i])
	{
		res[i] = f(i, a[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
