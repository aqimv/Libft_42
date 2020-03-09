/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:50:27 by skennith          #+#    #+#             */
/*   Updated: 2019/11/01 16:50:29 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_range(int min, int max)
{
	int		*x;
	int		i;
	int		a;

	if (max > min)
	{
		i = 0;
		a = min;
		x = malloc(sizeof(int) * (max - min));
		while (a < max)
		{
			x[i] = a;
			a++;
			i++;
		}
		return (x);
	}
	else
		return (NULL);
}
