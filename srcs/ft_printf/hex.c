/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:28:36 by skennith          #+#    #+#             */
/*   Updated: 2020/07/10 15:28:38 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				sharp_hex(t_pfstruct *data, intmax_t num)
{
	if (data->fs.flag.sharp && num != 0)
	{
		if (data->fs.type == 'X')
		{
			data->pfreturn += ft_putstrcount("0X");
		}
		else
		{
			data->pfreturn += ft_putstrcount("0x");
		}
		return (2);
	}
	return (0);
}

void			big_x(t_pfstruct *data)
{
	int			i;

	i = 0;
	while (data->fs.fnl[i])
	{
		if (data->fs.fnl[i] >= 'a' && data->fs.fnl[i] <= 'z')
			data->fs.fnl[i] = data->fs.fnl[i] - 32;
		i++;
	}
}

void			print_hex3(t_pfstruct *data, intmax_t num)
{
	if (data->fs.flag.zero)
	{
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		data->fs.wid -= sharp_hex(data, num);
		data->pfreturn += write_chars(data->fs.wid - \
			(int)ft_strlen(data->fs.fnl), '0');
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		data->pfreturn = write_chars(data->fs.wid - \
			ft_strlen(data->fs.fnl) - (data->fs.sign ? 1 : 0) - \
			(data->fs.flag.sharp && num != 0 ? 2 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		sharp_hex(data, num);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void			print_hex2(t_pfstruct *data, intmax_t num)
{
	precision_zero(data);
	if (!data->fs.wid)
	{
		if (data->fs.sign)
			data->pfreturn += write(1, &data->fs.sign, 1);
		sharp_hex(data, num);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		if (data->fs.flag.minus)
		{
			if (data->fs.sign)
			{
				data->pfreturn += write(1, &data->fs.sign, 1);
				data->fs.wid -= 1;
			}
			data->fs.wid -= sharp_hex(data, num);
			data->pfreturn += ft_putstrcount(data->fs.fnl);
			data->fs.wid -= ft_strlen(data->fs.fnl);
			data->pfreturn += write_chars(data->fs.wid, ' ');
		}
		else
			print_hex3(data, num);
	}
}

void			print_hex(t_pfstruct *data)
{
	intmax_t	num;

	if (data->fs.size.ll)
		num = (unsigned long long)va_arg(data->args, unsigned long long);
	else if (data->fs.size.l)
		num = (unsigned long int)va_arg(data->args, unsigned long int);
	else if (data->fs.size.h)
		num = (unsigned short int)va_arg(data->args, unsigned int);
	else if (data->fs.size.hh)
		num = (unsigned char)va_arg(data->args, unsigned int);
	else
		num = (unsigned int)va_arg(data->args, unsigned int);
	data->fs.sign = data->fs.flag.plus ? '+' : 0;
	data->fs.fnl = num == 0 && data->fs.pr_z && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(num, 16);
	if (data->fs.type == 'X')
		big_x(data);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= data->fs.wid || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= data->fs.wid)
		data->fs.wid = 0;
	print_hex2(data, num);
}
