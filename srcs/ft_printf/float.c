/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 23:48:50 by cspaghet          #+#    #+#             */
/*   Updated: 2020/07/24 23:48:56 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*subrounding(int k, char *num, int i)
{
	char *buf;

	while ((num[i - 1] == '9') && (i > 0) && (k == 10))
	{
		num[i - 1] = '0';
		k = num[i - 2] - '0';
		k += 1;
		i--;
	}
	num[i - 1] = k + '0';
	if (i == 0)
	{
		buf = num;
		num = ft_strjoin(".", num);
		ft_strdel(&buf);
	}
	return (num);
}

char			*rounding(char *num, int n, int whole)
{
	int			k;

	if ((n == 0) && (ft_strcmp(num, "5") == 0) && (whole % 2 == 0))
	{
		ft_strdel(&num);
		return (ft_strdup(""));
	}
	k = num[n] - '0';
	if (k >= 5)
	{
		if (n == 0)
		{
			ft_strdel(&num);
			return (ft_strdup("."));
		}
		k = num[n - 1] - '0';
		k += 1;
		if (k == 10)
			num = subrounding(k, num, n);
		else
			num[n - 1] = k + '0';
	}
	num[n] = '\0';
	return (num);
}

char			*frac(char *fraction, int round)
{
	char		*str;
	char		*buf;

	str = (char *)malloc(sizeof(char) * (round + 1));
	str[round] = '\0';
	ft_memset(str, '0', (size_t)round);
	if ((int)ft_strlen(fraction) < round)
	{
		ft_bzero(str, ft_strlen(str));
		ft_memset(str, '0', (size_t)round - ft_strlen(fraction));
		buf = fraction;
		fraction = ft_strjoin(fraction, str);
		ft_strdel(&buf);
	}
	ft_strdel(&str);
	return (fraction);
}

char			*float_to_string(long double num, int round, int whole)
{
	char		*integer;
	char		*fraction;
	char		*buf;

	whole = (int)num;
	fraction = rounding(from_bin(ft_ftoa_base2(num - whole)), round, whole);
	if (fraction[0] == '.')
	{
		whole += 1;
		buf = fraction;
		fraction = ft_strdup(&fraction[1]);
		ft_strdel(&buf);
	}
	integer = ft_itoa(whole);
	fraction = frac(fraction, round);
	if (round != 0)
	{
		buf = integer;
		integer = ft_strjoin(integer, ".");
		ft_strdel(&buf);
	}
	buf = ft_strjoin(integer, fraction);
	ft_strdel(&integer);
	ft_strdel(&fraction);
	return (buf);
}

void			print_float(t_pfstruct *data)
{
	long double	num;

	if (data->fs.size.big_l)
		num = (long double)va_arg(data->args, long double);
	else
		num = (long double)va_arg(data->args, double);
	if ((data->fs.precision == 0 && !data->fs.pr_z) || data->fs.precision < 0)
		data->fs.precision = 6;
	if (num < 0 || data->fs.flag.plus)
		data->fs.sign = num >= 0 ? '+' : '-';
	data->fs.fnl = float_to_string(md_double(num), data->fs.precision, 0);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= md(data->fs.wid) || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= md(data->fs.wid))
		data->fs.wid = 0;
	print_float2(data);
}
