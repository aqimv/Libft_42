/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:37:25 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:37:26 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_int4(t_pfstruct *data)
{
	if (data->fs.wid > 0)
	{
		sign_or_space(data);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
		data->fs.wid -= ft_strlen(data->fs.fnl);
		data->pfreturn += write_chars(data->fs.wid, ' ');
	}
	else
	{
		data->fs.wid = md(data->fs.wid);
		sign_or_space(data);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
		data->fs.wid += ft_strlen(data->fs.fnl);
		data->pfreturn += write_chars(md(data->fs.wid), ' ');
	}
}

void			print_int3(t_pfstruct *data)
{
	if (data->fs.flag.zero)
	{
		sign_or_space(data);
		data->pfreturn += write_chars(data->fs.wid - \
		(int)ft_strlen(data->fs.fnl), '0');
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		if (data->fs.flag.space && !data->fs.sign)
		{
			data->pfreturn += write(1, " ", 1);
			data->fs.wid -= 1;
		}
		data->pfreturn = write_chars(data->fs.wid - \
		ft_strlen(data->fs.fnl) - (data->fs.sign ? 1 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void			print_int2(t_pfstruct *data)
{
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= md(data->fs.wid) || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= md(data->fs.wid))
		data->fs.wid = 0;
	precision_zero(data);
	if (data->fs.wid == 0)
	{
		if (data->fs.sign)
			data->pfreturn += write(1, &data->fs.sign, 1);
		else if (data->fs.flag.space)
			data->pfreturn += write(1, " ", 1);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		if (data->fs.flag.minus || data->fs.wid < 0)
			print_int4(data);
		else
			print_int3(data);
	}
}

void			print_int(t_pfstruct *data)
{
	intmax_t	num;

	if (data->fs.size.ll)
		num = (long long int)va_arg(data->args, long long int);
	else if (data->fs.size.l)
		num = (long int)va_arg(data->args, long int);
	else if (data->fs.size.h)
		num = (short int)va_arg(data->args, int);
	else if (data->fs.size.hh)
		num = (signed char)va_arg(data->args, int);
	else
		num = (int)va_arg(data->args, int);
	if (num < 0 || data->fs.flag.plus)
		data->fs.sign = num >= 0 ? '+' : '-';
	num < 0 ? num *= -1 : num;
	if (data->fs.wid < 0)
	{
		data->fs.flag.minus = 1;
		data->fs.wid = md(data->fs.wid);
	}
	data->fs.fnl = num == 0 && data->fs.pr_z && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(num, 10);
	print_int2(data);
}
