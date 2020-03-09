/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:06:34 by skennith          #+#    #+#             */
/*   Updated: 2019/09/10 18:06:36 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	if (!arr1 && !arr2)
		return (0);
	a = (char *)arr1;
	b = (char *)arr2;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return ((unsigned char)a[i - 1] - (unsigned char)b[i - 1]);
}
