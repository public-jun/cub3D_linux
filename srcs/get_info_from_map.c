/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:47:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 18:45:36 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_store_sprite_coordinate(t_all *all, int x, int y)
{
	all->sprite_info.order[all->sprite_info.tmp].sp_x = (double)x + 0.5;
	all->sprite_info.order[all->sprite_info.tmp].sp_y = (double)y + 0.5;
	all->sprite_info.tmp++;
}

void			ft_get_info_from_map(t_all *all,
										char map[MAP_HEIGHT][MAP_WIDTH])
{
	int			x;
	int			y;
	char		tmp;

	y = 1;
	while (y < MAP_HEIGHT - 1)
	{
		x = 1;
		while (x < MAP_WIDTH - 1)
		{
			if (map[y][x] == '2')
				ft_store_sprite_coordinate(all, x, y);
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				ft_store_player_info(all, map, x, y);
				map[y][x] = '0';
			}
			tmp = map[y][x];
			all->map.int_map[y][x] = ft_atoi(&tmp);
			x++;
		}
		y++;
	}
}

void			ft_make_xy_map(t_all *all)
{
	int			x;
	int			y;

	x = 0;
	while (x < MAP_WIDTH)
	{
		y = 0;
		while (y < MAP_HEIGHT)
		{
			all->map.xy_map[x][y] = all->map.int_map[y][x];
			y++;
		}
		x++;
	}
}

void			ft_r_map(t_all *all)
{
	int			y;
	int			x;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			all->map.char_r_map[y][x] =
					all->map.char_map[MAP_HEIGHT - 1 - y][x];
			x++;
		}
		y++;
	}
}

void			ft_set_data_for_raycast(t_all *all)
{
	ft_r_map(all);
	if (all->sprite_info.num > 0)
	{
		if (!(all->sprite_info.order =
				(t_sprite*)malloc(sizeof(t_sprite) * all->sprite_info.num)))
			ft_put_error_and_exit(all, NULL, "Cant allocate memory\n");
		if (all->sprite_info.order == NULL)
			ft_put_error_and_exit(all, NULL, "cant malloc!\n");
	}
	ft_get_info_from_map(all, all->map.char_r_map);
	ft_make_xy_map(all);
}
