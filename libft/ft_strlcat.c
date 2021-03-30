/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:52:29 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/12 17:17:40 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	size_t			src_len;
	unsigned int	i;
	unsigned int	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len)
	{
		i = dst_len;
		j = 0;
		while (src[j] && dstsize - 1 > i)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}
