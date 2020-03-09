/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:56:35 by skennith          #+#    #+#             */
/*   Updated: 2019/09/12 14:56:37 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	char	*a;
	char	*b;

	a = (char *)str2;
	b = (char *)str1;
	i = 0;
	if (ft_strlen(a) == 0)
		return ((char *)&b[0]);
	while (b[i])
	{
		if (b[i] == a[0])
		{
			if ((ft_memcmp(&a[0], &b[i], (int)ft_strlen(a))) == 0)
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
