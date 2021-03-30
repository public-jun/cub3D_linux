/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:29:41 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/27 21:42:37 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count_len;
	char			*ans;
	unsigned int	i;

	if (!s)
		return (NULL);
	count_len = ft_strlen(s);
	if (len <= 0 || start >= count_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > count_len - start)
		len = count_len - start;
	if (!(ans = malloc((sizeof(char) * len) + 1)))
		return (NULL);
	i = 0;
	while (len--)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
