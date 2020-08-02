/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:37:48 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:37:50 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision_string(t_pfstruct *data)
{
	char	*buf;

	buf = data->fs.fnl;
	if (data->fs.precision < (int)ft_strlen(data->fs.fnl) \
	&& data->fs.pr_z != 0 && data->fs.precision >= 0)
	{
		data->fs.fnl = ft_strnew(data->fs.precision);
		data->fs.fnl = ft_strncpy(data->fs.fnl, buf, \
		data->fs.precision);
		ft_strdel(&buf);
	}
}

void		print_string2(t_pfstruct *data, int check, int len, char ch)
{
	if (data->fs.flag.minus || check)
	{
		data->pfreturn += ft_putstrcount(data->fs.fnl);
		data->pfreturn += write_chars(len, ch);
	}
	else
	{
		data->pfreturn += write_chars(len, ch);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void		print_string(t_pfstruct *data)
{
	char	ch;
	int		len_ch;
	int		check_w;

	ch = data->fs.flag.zero ? '0' : ' ';
	data->fs.fnl = (char *)va_arg(data->args, char *);
	if (data->fs.fnl == NULL)
		data->fs.fnl = ft_strdup("(null)");
	else
		data->fs.fnl = ft_strdup(data->fs.fnl);
	precision_string(data);
	check_w = data->fs.wid < 0 ? 1 : 0;
	data->fs.wid = data->fs.wid < 0 ? data->fs.wid * -1 : data->fs.wid;
	len_ch = data->fs.wid - (int)ft_strlen(data->fs.fnl);
	if (len_ch > 0)
		print_string2(data, check_w, len_ch, ch);
	else
		data->pfreturn += ft_putstrcount(data->fs.fnl);
}
