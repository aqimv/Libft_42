/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:16:20 by skennith          #+#    #+#             */
/*   Updated: 2020/07/21 23:16:22 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				md(int i)
{
	return (i >= 0 ? i : i * -1);
}

long double		md_double(long double i)
{
	return (i >= 0 ? i : i * -1);
}
