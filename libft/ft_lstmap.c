/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:17:48 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 18:22:18 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_ele;

	if (!lst || !f)
		return (NULL);
	new_ele = ft_lstnew((*f)(lst->content));
	if (new_ele == NULL)
		return (NULL);
	new_list = new_ele;
	lst = lst->next;
	while (lst)
	{
		new_ele = ft_lstnew((*f)(lst->content));
		if (new_ele == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_ele);
		lst = lst->next;
	}
	return (new_list);
}
