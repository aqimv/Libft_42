/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:25:46 by skennith          #+#    #+#             */
/*   Updated: 2020/01/21 17:21:26 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include "libft.h"
# include <fcntl.h>

typedef struct					s_gnl_list
{
	int							fd;
	char						*remainder;
	struct s_gnl_list			*next;
}								t_gnl;

int								get_next_line(const int fd, char **line);

#endif
