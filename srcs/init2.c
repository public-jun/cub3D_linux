/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:21:09 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/28 16:30:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_init_t_flag(t_all *all)
{
	all->flag.eflag = 0;
	all->flag.r = 0;
	all->flag.no = 0;
	all->flag.so = 0;
	all->flag.we = 0;
	all->flag.ea = 0;
	all->flag.s = 0;
	all->flag.f = 0;
	all->flag.c = 0;
	all->flag.except_map = 0;
	all->flag.mlx_start = 0;
}

void			ft_init_t_win_r(t_all *all)
{
	all->win_r.x = 0;
	all->win_r.y = 0;
	all->win_r.screen_x = 0;
	all->win_r.screen_y = 0;
}

void			ft_init_t_path(t_all *all)
{
	all->path_tex.north = NULL;
	all->path_tex.south = NULL;
	all->path_tex.west = NULL;
	all->path_tex.east = NULL;
	all->path_tex.sprite = NULL;
}

void			ft_init_t_map(t_all *all)
{
	all->map.pflag = 0;
	all->map.cont = 0;
	all->map.tmp_y = 1;
	all->map.p_x = 0;
	all->map.p_y = 0;
}

void			ft_init_t_info(t_all *all)
{
	all->sprite_info.num = 0;
	all->sprite_info.order = NULL;
	all->sprite_info.tmp = 0;
	all->sprite_info.zbuffer = NULL;
	all->info.texture = NULL;
	all->info.buf = NULL;
}
