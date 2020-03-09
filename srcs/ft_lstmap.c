/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:54:12 by skennith          #+#    #+#             */
/*   Updated: 2019/09/27 15:54:13 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lstclear(t_list *lst)
{
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	free(lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*res;
	t_list		*a;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	if (!(res = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	lst = lst->next;
	a = res;
	while (lst)
	{
		list = f(lst);
		if (!(a->next = ft_lstnew(list->content, list->content_size)))
		{
			lstclear(res);
			return (NULL);
		}
		a = a->next;
		lst = lst->next;
	}
	return (res);
}
