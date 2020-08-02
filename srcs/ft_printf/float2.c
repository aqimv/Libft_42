/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 23:49:16 by cspaghet          #+#    #+#             */
/*   Updated: 2020/07/24 23:49:22 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*sum1(char *s1, char *s2)
{
	int		carry;
	int		sum;
	int		i;

	i = ft_strlen(s1) - 1;
	carry = 0;
	while (i >= 0)
	{
		sum = (s2[i] - '0') + (s1[i] - '0');
		sum += carry;
		if (sum >= 10)
		{
			sum -= 10;
			s2[i] = (char)(sum + '0');
			carry = 1;
		}
		else
		{
			s2[i] = (char)(sum + '0');
			carry = 0;
		}
		i = i - 1;
	}
	ft_strdel(&s1);
	return (s2);
}

char		*from_bin(char *str)
{
	char	*k;
	int		i;
	char	*pow;

	k = ft_strnew(0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] - '0') == 1)
		{
			pow = power2(i + 1);
			k = sum1(k, pow);
		}
		i++;
	}
	ft_strdel(&str);
	return (k);
}

char		*ft_ftoa_base2(long double num)
{
	int		i;
	char	*ans;

	if (!(ans = (char *)malloc(sizeof(char) * 151)))
		return (NULL);
	ans[150] = '\0';
	i = 0;
	while (num != 1.0 && i < 150)
	{
		num = num * 2;
		ans[i] = (int)num + '0';
		if (num > 1)
			num = num - 1;
		i++;
	}
	while (i < 150)
	{
		ans[i] = '0';
		i++;
	}
	return (ans);
}
