/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:00:42 by skennith          #+#    #+#             */
/*   Updated: 2019/11/05 18:00:44 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(char *str)
{
	int	i;
	int	counter;
	int	x;

	counter = 0;
	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			i++;
			x = 1;
		}
		if (x)
		{
			counter++;
			x = 0;
		}
		i++;
	}
	return (counter);
}
