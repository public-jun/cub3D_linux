/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:56:00 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 18:36:56 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_set_ray_data(t_all *all, int x)
{
	all->ray.camera_x = 2 * x / (double)all->win_r.x - 1;
	all->ray.raydir_x = all->player.dir_x + all->player.plane_x
							* all->ray.camera_x;
	all->ray.raydir_y = all->player.dir_y + all->player.plane_y
							* all->ray.camera_x;
	all->ray.map_x = (int)all->player.pos_x;
	all->ray.map_y = (int)all->player.pos_y;
	all->ray.deltadist_x = ft_abs(1 / all->ray.raydir_x);
	all->ray.deltadist_y = ft_abs(1 / all->ray.raydir_y);
	all->ray.hit = 0;
}

void			ft_check_raydir_and_set_sidedist(t_all *all)
{
	if (all->ray.raydir_x < 0)
	{
		all->ray.step_x = -1;
		all->ray.sidedist_x = (all->player.pos_x - all->ray.map_x)
									* all->ray.deltadist_x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.sidedist_x = (all->ray.map_x + 1.0 - all->player.pos_x)
									* all->ray.deltadist_x;
	}
	if (all->ray.raydir_y < 0)
	{
		all->ray.step_y = -1;
		all->ray.sidedist_y = (all->player.pos_y - all->ray.map_y)
									* all->ray.deltadist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.sidedist_y = (all->ray.map_y + 1.0 - all->player.pos_y)
									* all->ray.deltadist_y;
	}
}

void			ft_find_collision_with_wall(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sidedist_x < all->ray.sidedist_y)
		{
			all->ray.sidedist_x += all->ray.deltadist_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.sidedist_y += all->ray.deltadist_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map.xy_map[all->ray.map_x][all->ray.map_y] == 1)
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		all->ray.prepwalldist = (all->ray.map_x - all->player.pos_x
							+ (1 - all->ray.step_x) / 2) / all->ray.raydir_x;
	else
		all->ray.prepwalldist = (all->ray.map_y - all->player.pos_y
							+ (1 - all->ray.step_y) / 2) / all->ray.raydir_y;
}

void			ft_calculate_wall_height_on_screen(t_all *all)
{
	all->ray.lineheight = (int)(all->win_r.y / all->ray.prepwalldist);
	all->ray.drawstart = -all->ray.lineheight / 2 + all->win_r.y / 2;
	if (all->ray.drawstart < 0)
		all->ray.drawstart = 0;
	all->ray.drawend = all->ray.lineheight / 2 + all->win_r.y / 2;
	if (all->ray.drawend >= all->win_r.y)
		all->ray.drawend = all->win_r.y - 1;
}

void			ft_wall_casting(t_all *all)
{
	int			x;

	x = 0;
	while (x < all->win_r.x)
	{
		ft_set_ray_data(all, x);
		ft_check_raydir_and_set_sidedist(all);
		ft_find_collision_with_wall(all);
		ft_calculate_wall_height_on_screen(all);
		ft_set_direction_tex(all);
		ft_attach_tex_size_for_screen(all, &all->tex);
		ft_set_buf(all, x);
		x++;
	}
}
