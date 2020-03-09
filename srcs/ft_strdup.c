/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:20:27 by skennith          #+#    #+#             */
/*   Updated: 2019/09/10 19:20:29 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*c;
	int		i;

	if (ft_strlen(str) > (ft_strlen(str) + 1))
		return (0);
	c = malloc(ft_strlen(str) + 1);
	i = 0;
	if (c)
	{
		while (str[i])
		{
			c[i] = str[i];
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	else
		return (NULL);
}
