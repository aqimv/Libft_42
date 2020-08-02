/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:58:06 by skennith          #+#    #+#             */
/*   Updated: 2020/07/01 19:58:09 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_size(t_pfstruct *data)
{
	data->fs.size.l = 0;
	data->fs.size.ll = 0;
	data->fs.size.h = 0;
	data->fs.size.hh = 0;
	data->fs.size.big_l = 0;
}

void		pf_init(t_pfstruct *data)
{
	data->str = NULL;
	data->fs.str = NULL;
	data->fs.fnl = NULL;
	data->fs.type = 0;
	data->fs.wid = 0;
	data->fs.precision = 0;
	data->fs.sign = 0;
	data->fs.pr_z = 0;
	data->fs.flag.zero = 0;
	data->fs.flag.minus = 0;
	data->fs.flag.plus = 0;
	data->fs.flag.space = 0;
	data->fs.flag.sharp = 0;
	init_size(data);
}

void		deinit_size(t_pfstruct *data)
{
	data->fs.size.l = 0;
	data->fs.size.ll = 0;
	data->fs.size.h = 0;
	data->fs.size.hh = 0;
	data->fs.size.big_l = 0;
}

void		deinit(t_pfstruct *data)
{
	if (data->fs.str != NULL)
		ft_strdel(&data->fs.str);
	if (data->fs.fnl != NULL)
		ft_strdel(&data->fs.fnl);
	data->fs.type = 0;
	data->fs.wid = 0;
	data->fs.precision = 0;
	data->fs.sign = 0;
	data->fs.pr_z = 0;
	data->fs.flag.zero = 0;
	data->fs.flag.minus = 0;
	data->fs.flag.plus = 0;
	data->fs.flag.space = 0;
	data->fs.flag.sharp = 0;
	deinit_size(data);
}
