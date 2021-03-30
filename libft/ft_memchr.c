/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:39:42 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/10 17:50:52 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *puc_s;
	unsigned char		uc_c;

	puc_s = s;
	uc_c = c;
	while (n--)
	{
		if (*puc_s == uc_c)
			return ((void*)puc_s);
		puc_s++;
	}
	return (NULL);
}
