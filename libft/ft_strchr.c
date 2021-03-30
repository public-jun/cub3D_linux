/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:56:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 12:22:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ('\0' == (char)c)
		return ((char *)s);
	return (NULL);
}

int			ft_strchr_n(const char *need, const char c)
{
	size_t	need_len;
	int		type_index;

	need_len = 0;
	need_len = ft_strlen(need);
	type_index = 0;
	while (type_index < (int)need_len)
	{
		if (need[type_index] == c)
			return (type_index);
		type_index++;
	}
	return (-1);
}
