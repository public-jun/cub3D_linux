/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:41:39 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 19:07:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_each_len(char const *s, char c, int i)
{
	int		each_len;

	each_len = 0;
	while (s[i] != c && s[i])
	{
		each_len++;
		i++;
	}
	return (each_len);
}

static char	**free_malloc(char **ans, int word_index)
{
	while (word_index > 0)
	{
		word_index--;
		free((void *)ans[word_index]);
	}
	free((void *)ans);
	return (NULL);
}

static int	make_word(int each_len, char *tmp_str, char const *s,
							int tmp_index)
{
	int	i;

	i = 0;
	while (i < each_len)
	{
		tmp_str[i] = s[tmp_index + i];
		i++;
	}
	tmp_str[i] = '\0';
	tmp_index = tmp_index + i;
	return (tmp_index);
}

static char	**make_ans(char **ans, char const *s, char c, int word_counts)
{
	char	*tmp_str;
	int		word_index;
	int		tmp_index;
	int		each_len;

	tmp_index = 0;
	word_index = 0;
	while (s[tmp_index] && word_index < word_counts)
	{
		while (s[tmp_index] == c)
			tmp_index++;
		each_len = count_each_len(s, c, tmp_index);
		ans[word_index] = (char *)malloc(sizeof(char) * (each_len + 1));
		if (ans[word_index] == NULL)
			return (free_malloc(ans, word_index));
		tmp_str = ans[word_index++];
		tmp_index = make_word(each_len, tmp_str, s, tmp_index);
	}
	ans[word_index] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		word_counts;

	if (!s)
		return (NULL);
	i = 0;
	word_counts = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_counts++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	ans = (char **)malloc(sizeof(char *) * (word_counts + 1));
	if (ans == NULL)
		return (NULL);
	ans = make_ans(ans, s, c, word_counts);
	return (ans);
}
