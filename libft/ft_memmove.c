/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:13:49 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/23 21:12:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	uc_dst = (unsigned char*)dst;
	uc_src = (unsigned char*)src;
	i = 0;
	if (uc_src < uc_dst && uc_dst <= uc_src + len)
	{
		while (i <= len - 1)
		{
			uc_dst[(len - 1) - i] = uc_src[(len - 1) - i];
			i++;
		}
	}
	else
	{
		while (len--)
			*uc_dst++ = *uc_src++;
	}
	return (dst);
}
