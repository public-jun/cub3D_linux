/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:39:55 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 18:23:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counts;

	if (!lst)
		return (0);
	counts = 0;
	while (lst)
	{
		counts++;
		lst = lst->next;
	}
	return (counts);
}
