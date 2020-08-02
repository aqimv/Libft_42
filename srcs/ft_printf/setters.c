/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:21:56 by skennith          #+#    #+#             */
/*   Updated: 2020/07/03 18:22:06 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_flag(t_pfstruct *data, char ch)
{
	if (ch == '-')
		data->fs.flag.minus = 1;
	else if (ch == '+')
		data->fs.flag.plus = 1;
	else if (ch == '0')
		data->fs.flag.zero = 1;
	else if (ch == ' ')
		data->fs.flag.space = 1;
	else if (ch == '#')
		data->fs.flag.sharp = 1;
	return (0);
}

int		set_size(t_pfstruct *data, int *i)
{
	if (data->fs.str[*i] != data->fs.str[*i + 1])
	{
		if (data->fs.str[*i] == 'l')
			data->fs.size.l = 1;
		else if (data->fs.str[*i] == 'h')
			data->fs.size.h = 1;
		else if (data->fs.str[*i] == 'L')
			data->fs.size.big_l = 1;
	}
	else
	{
		if (data->fs.str[*i] == 'l' && data->fs.str[*i + 1] == 'l')
			data->fs.size.ll = 1;
		else if (data->fs.str[*i] == 'h' && data->fs.str[*i + 1] == 'h')
			data->fs.size.hh = 1;
		*i = *i + 1;
	}
	return (0);
}

int		set_width(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.wid = va_arg(data->args, int);
	else if (data->fs.wid == 0)
		data->fs.wid += ft_atoi(&ch);
	else
		data->fs.wid = (data->fs.wid * 10) + ft_atoi(&ch);
	return (0);
}

int		set_precision(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.precision = va_arg(data->args, int);
	else if (data->fs.precision == 0)
		data->fs.precision += ft_atoi(&ch);
	else
		data->fs.precision = (data->fs.precision * 10) + ft_atoi(&ch);
	return (0);
}
