/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:31:33 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 19:04:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_draw_to_window(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	while (y < all->win_r.y)
	{
		x = 0;
		while (x < all->win_r.x)
		{
			all->info.img.data[(all->info.img.size_l / (all->info.img.bpp / 8))
											* y + x] = all->info.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->info.mlx, all->info.win,
								all->info.img.img_ptr, 0, 0);
}

int				ft_raycasting(t_all *all)
{
	floor_and_ceilling_casting(all);
	ft_wall_casting(all);
	ft_sprite_casting(all);
	ft_draw_to_window(all);
	// key_action(all);
	return (0);
}
