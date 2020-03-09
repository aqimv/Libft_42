/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:49:44 by skennith          #+#    #+#             */
/*   Updated: 2019/09/10 17:49:46 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	ch = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (ch[i] == (unsigned char)c)
			return (&ch[i]);
		i++;
	}
	return (NULL);
}
