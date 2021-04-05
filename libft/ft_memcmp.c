/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:48:03 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 19:01:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
