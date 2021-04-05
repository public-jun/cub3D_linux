/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 19:17:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*make_ans(size_t len_s1, size_t len_s2,
							char const *s1, char const *s2)
{
	char	*ans;
	int		i;

	i = 0;
	ans = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (ans == NULL)
		return (NULL);
	if (s1)
	{
		while (*s1)
			ans[i++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			ans[i++] = *s2++;
	}
	ans[i] = '\0';
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ans;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 && !s2)
	{
		ans = malloc(1);
		if (ans == NULL)
			return (NULL);
		*ans = '\0';
		return (ans);
	}
	else if (!s1)
	{
		len_s2 = ft_strlen(s2);
		return (make_ans(0, len_s2, s1, s2));
	}
	else if (!s2)
	{
		len_s1 = ft_strlen(s1);
		return (make_ans(len_s1, 0, s1, s2));
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (make_ans(len_s1, len_s2, s1, s2));
}
