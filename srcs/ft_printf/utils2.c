/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 23:49:46 by cspaghet          #+#    #+#             */
/*   Updated: 2020/07/24 23:49:50 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*mult_on_half(char *s1, int i, int a)
{
	char	*result;
	int		x;

	result = ft_strnew(ft_strlen(s1) + 1);
	ft_memset(result, '0', ft_strlen(s1) + 1);
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		x = (s1[i] - '0') * 5;
		x += a;
		a = 0;
		if (x > 9)
		{
			result[i + 1] = (char)((x % 10) + '0');
			a = x / 10;
		}
		else
			result[i + 1] = (char)((x + a) + '0');
		i--;
	}
	if (a > 0)
		result[i + 1] = (char)(a + '0');
	return (result);
}

char		*power2(int pow)
{
	char	*ans;
	char	*buf;

	pow--;
	ans = ft_strdup("5");
	while (pow != 0)
	{
		buf = ans;
		ans = mult_on_half(ans, 0, 0);
		ft_strdel(&buf);
		pow--;
	}
	return (ans);
}
