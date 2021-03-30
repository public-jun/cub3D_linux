/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:29:51 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:46:48 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_move_forward(t_all *all)
{
	if (!all->map.xy_map[(int)(all->player.pos_x
		+ all->player.dir_x * all->info.move_speed)][(int)(all->player.pos_y)])
		all->player.pos_x += all->player.dir_x * all->info.move_speed;
	if (!all->map.xy_map[(int)(all->player.pos_x)]
		[(int)(all->player.pos_y + all->player.dir_y * all->info.move_speed)])
		all->player.pos_y += all->player.dir_y * all->info.move_speed;
}

void			ft_move_backward(t_all *all)
{
	if (!all->map.xy_map[(int)(all->player.pos_x
		- all->player.dir_x * all->info.move_speed)][(int)(all->player.pos_y)])
		all->player.pos_x -= all->player.dir_x * all->info.move_speed;
	if (!all->map.xy_map[(int)(all->player.pos_x)]
		[(int)(all->player.pos_y - all->player.dir_y * all->info.move_speed)])
		all->player.pos_y -= all->player.dir_y * all->info.move_speed;
}

void			ft_move_right(t_all *all)
{
	if (!all->map.xy_map[(int)(all->player.pos_x
		+ all->player.plane_x * all->info.move_speed)]
		[(int)(all->player.pos_y)])
		all->player.pos_x += all->player.plane_x * all->info.move_speed;
	if (!all->map.xy_map[(int)(all->player.pos_x)]
		[(int)(all->player.pos_y + all->player.plane_y * all->info.move_speed)])
		all->player.pos_y += all->player.plane_y * all->info.move_speed;
}

void			ft_move_left(t_all *all)
{
	if (!all->map.xy_map[(int)(all->player.pos_x
		- all->player.plane_x * all->info.move_speed)]
		[(int)(all->player.pos_y)])
		all->player.pos_x -= all->player.plane_x * all->info.move_speed;
	if (!all->map.xy_map[(int)(all->player.pos_x)]
		[(int)(all->player.pos_y - all->player.plane_y * all->info.move_speed)])
		all->player.pos_y -= all->player.plane_y * all->info.move_speed;
}
