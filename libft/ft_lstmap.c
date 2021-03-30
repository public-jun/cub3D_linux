/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:17:48 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/27 21:31:52 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_ele;

	if (!lst || !f)
		return (NULL);
	if (!(new_ele = ft_lstnew((*f)(lst->content))))
		return (NULL);
	new_list = new_ele;
	lst = lst->next;
	while (lst)
	{
		if (!(new_ele = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_ele);
		lst = lst->next;
	}
	return (new_list);
}
