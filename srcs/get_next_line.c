/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:25:25 by skennith          #+#    #+#             */
/*   Updated: 2019/10/05 16:25:26 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*check_r(char **r, char **np)
{
	char			*str;

	if ((*np = ft_strchr(*r, '\n')))
	{
		**np = '\0';
		str = ft_strdup(*r);
		ft_strcpy(*r, ++(*np));
	}
	else
	{
		str = ft_strnew(ft_strlen(*r) + 1);
		ft_strcat(str, *r);
		ft_strclr(*r);
	}
	return (str);
}

static int			gnl(const int fd, char **line, char **r)
{
	int				i;
	char			buf[BUFF_SIZE + 1];
	char			*np;
	char			*cl;

	np = NULL;
	*line = check_r(r, &np);
	while (!np && (i = read(fd, buf, BUFF_SIZE)))
	{
		if (i < 0)
			return (-1);
		buf[i] = '\0';
		if ((np = ft_strchr(buf, '\n')))
		{
			ft_strcpy(*r, ++np);
			ft_strclr(--np);
		}
		cl = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		ft_strdel(&cl);
	}
	return (ft_strlen(*r) || i || ft_strlen(*line) ? 1 : 0);
}

static t_gnl		*newt_gnl(int fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->remainder = ft_strnew(BUFF_SIZE + 1);
	new->next = NULL;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*first;
	t_gnl			*tmp;

	if (!line || fd < 0)
		return (-1);
	if (!first)
		first = newt_gnl(fd);
	tmp = first;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
			tmp->next = newt_gnl(fd);
		tmp = tmp->next;
	}
	return (gnl(tmp->fd, line, &tmp->remainder));
}
