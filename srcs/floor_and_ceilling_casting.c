/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceilling_casting.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:23:36 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/26 20:25:50 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_and_ceilling_casting(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	while (y < all->win_r.y / 2)
	{
		x = 0;
		while (x < all->win_r.x)
		{
			all->info.buf[y][x] = all->color_c.rgb;
			all->info.buf[all->win_r.y - 1 - y][x] = all->color_f.rgb;
			x++;
		}
		y++;
	}
}
