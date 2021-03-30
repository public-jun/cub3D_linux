/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:23:39 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:34:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			ft_init_char_map(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (x == 0 || x == MAP_WIDTH - 1 || y == 0 || y == MAP_HEIGHT - 1)
				all->map.char_map[y][x] = 'x';
			else
				all->map.char_map[y][x] = '0';
			x++;
		}
		y++;
	}
}

static void			ft_init_int_map(t_all *all)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			all->map.int_map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void				ft_init_all(t_all *all, int ac)
{
	ft_init_t_flag(all);
	ft_init_t_win_r(all);
	ft_init_t_path(all);
	ft_init_t_map(all);
	ft_init_t_info(all);
	if (ac == 3)
		all->save = 1;
	else
		all->save = 0;
}

void				ft_init(t_all *all, int ac)
{
	ft_init_all(all, ac);
	ft_init_char_map(all);
	ft_init_int_map(all);
}
