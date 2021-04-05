/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:57:52 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 19:15:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		dstsize;

	dstsize = ((ft_strlen(s1) + 1) * sizeof(char));
	ptr = malloc(dstsize);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, dstsize);
	return (ptr);
}
