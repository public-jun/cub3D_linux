/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:47:21 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 15:37:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_dir(t_all *all, double dir_x, double dir_y)
{
	all->player.dir_x = dir_x;
	all->player.dir_y = dir_y;
}

void	ft_set_plane(t_all *all, double plane_x, double plane_y)
{
	all->player.plane_x = plane_x;
	all->player.plane_y = plane_y;
}

void	ft_store_player_dir_and_plane(t_all *all,
	char map[MAP_HEIGHT][MAP_WIDTH], int x, int y)
{
	if (map[y][x] == 'N')
	{
		ft_set_dir(all, 0.0, 1.0);
		ft_set_plane(all, 0.66, 0.0);
	}
	else if (map[y][x] == 'S')
	{
		ft_set_dir(all, 0.0, -1.0);
		ft_set_plane(all, -0.66, 0.0);
	}
	else if (map[y][x] == 'E')
	{
		ft_set_dir(all, 1.0, 0.0);
		ft_set_plane(all, 0.0, -0.66);
	}
	else if (map[y][x] == 'W')
	{
		ft_set_dir(all, -1.0, 0.0);
		ft_set_plane(all, 0.0, 0.66);
	}
}

void	ft_store_player_info(t_all *all,
	char map[MAP_HEIGHT][MAP_WIDTH], int x, int y)
{
	all->player.pos_x = (double)x + 0.5;
	all->player.pos_y = (double)y + 0.5;
	all->map.p_x = x;
	all->map.p_y = y;
	all->info.move_speed = 0.0677;
	all->info.rot_speed = 0.05;
	ft_store_player_dir_and_plane(all, map, x, y);
}
