/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:14:25 by skennith          #+#    #+#             */
/*   Updated: 2019/09/11 16:14:27 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *ap, size_t n)
{
	size_t	s;

	s = ft_strlen(dst);
	if (n > s)
		ft_strncat(dst, ap, (n - s - 1));
	else if (n < s)
		return (n + ft_strlen(ap));
	return (s + ft_strlen(ap));
}
