/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:16:18 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 19:18:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				s_len;
	unsigned int	i;
	char			*ans;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	ans = malloc(sizeof(char) * (s_len + 1));
	if (ans == NULL)
		return (NULL);
	while (s[i])
	{
		ans[i] = (*f)(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
