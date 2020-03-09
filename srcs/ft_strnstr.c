/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:32:04 by skennith          #+#    #+#             */
/*   Updated: 2019/09/13 16:32:06 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		a;

	i = 0;
	if (ft_strlen((char *)str2) == 0)
		return ((char *)&str1[0]);
	while (str1[i] && i < len)
	{
		j = 0;
		a = i;
		if (str1[i] == str2[j])
		{
			while (str2[j] && str1[i] && str1[i] == str2[j] && (i < len))
			{
				i++;
				j++;
			}
			if (str2[j] == '\0')
				return ((char *)&str1[i - j]);
		}
		i = a;
		i++;
	}
	return (NULL);
}
