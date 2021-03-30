/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:01:36 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/20 15:13:11 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*return_enpty(void)
{
	char	*ans;

	if (!(ans = malloc(1)))
		return (NULL);
	*ans = '\0';
	return (ans);
}

static	char	*find_ch(size_t i, char const *s1, char const *set,
						int add_back)
{
	int		j;
	int		match_flag;

	while (s1[i])
	{
		j = 0;
		match_flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				match_flag = 1;
			j++;
		}
		if (match_flag == 0)
			return ((char*)&s1[i]);
		i = i + add_back;
	}
	return (NULL);
}

static	char	*make_ans(char *p_first, size_t ans_len)
{
	char	*ans;
	int		i;

	if (!(ans = malloc(sizeof(char) * ans_len + 1)))
		return (NULL);
	i = 0;
	while (ans_len--)
		ans[i++] = *p_first++;
	ans[i] = '\0';
	return (ans);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*p_first;
	char	*p_last;
	size_t	len_s1;
	size_t	ans_len;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (return_enpty());
	if (!(p_first = find_ch(0, s1, set, 1)))
		return (return_enpty());
	p_last = NULL;
	len_s1 = ft_strlen(s1);
	p_last = find_ch(len_s1 - 1, s1, set, -1);
	ans_len = p_last - p_first + 1;
	return (make_ans(p_first, ans_len));
}
