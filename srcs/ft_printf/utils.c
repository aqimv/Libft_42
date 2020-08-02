/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:38:33 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:38:34 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_putstrcount(char const *s)
{
	int						count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		ft_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

int							write_chars(int i, char ch)
{
	char					count;

	count = 0;
	while (i > 0)
	{
		write(1, &ch, 1);
		i--;
		count++;
	}
	return (count);
}

char						*ft_itoa_base(uintmax_t num, uintmax_t not)
{
	unsigned long long int	n;
	char					*str;
	int						i;

	i = 1;
	n = num;
	while ((n /= not) >= 1)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = num;
	while (i-- > 0)
	{
		if (n % not < 10)
			str[i] = n % not + '0';
		else
			str[i] = n % not + 'a' - 10;
		n /= not;
	}
	return (str);
}

void						precision_zero(t_pfstruct *data)
{
	int						precision;
	char					*buf;

	precision = data->fs.precision - (int)ft_strlen(data->fs.fnl);
	while (precision > 0)
	{
		buf = data->fs.fnl;
		data->fs.fnl = ft_strjoin("0", data->fs.fnl);
		ft_strdel(&buf);
		precision--;
	}
}

void						sign_or_space(t_pfstruct *data)
{
	if (data->fs.sign)
	{
		data->pfreturn += write(1, &data->fs.sign, 1);
		data->fs.wid -= 1;
	}
	else if (data->fs.flag.space)
	{
		data->pfreturn += write(1, " ", 1);
		data->fs.wid -= 1;
	}
}
