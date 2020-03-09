/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:35:04 by skennith          #+#    #+#             */
/*   Updated: 2019/09/12 14:35:05 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*b;

	b = (char *)str;
	i = (int)ft_strlen(str);
	if (ch == '\0')
		return (&b[ft_strlen(str)]);
	while (i >= 0)
	{
		if (b[i] == ch)
			return (&b[i]);
		i--;
	}
	return (NULL);
}
