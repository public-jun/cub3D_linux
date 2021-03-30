/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:06:46 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 18:07:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_count_contents(char **dst)
{
	int			res;

	if (dst == NULL)
		return (0);
	res = 0;
	while (dst[res])
		res++;
	return (res);
}
