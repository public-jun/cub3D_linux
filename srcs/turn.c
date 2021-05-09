/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:30:54 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 18:03:10 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_turn_right(t_all *all)
{
	all->ray.olddir_x = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(-all->info.rot_speed)
		- all->player.dir_y * sin(-all->info.rot_speed);
	all->player.dir_y = all->ray.olddir_x * sin(-all->info.rot_speed)
		+ all->player.dir_y * cos(-all->info.rot_speed);
	all->ray.oldplane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(-all->info.rot_speed)
		- all->player.plane_y * sin(-all->info.rot_speed);
	all->player.plane_y = all->ray.oldplane_x * sin(-all->info.rot_speed)
		+ all->player.plane_y * cos(-all->info.rot_speed);
}

void	ft_turn_left(t_all *all)
{
	all->ray.olddir_x = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(all->info.rot_speed)
		- all->player.dir_y * sin(all->info.rot_speed);
	all->player.dir_y = all->ray.olddir_x * sin(all->info.rot_speed)
		+ all->player.dir_y * cos(all->info.rot_speed);
	all->ray.oldplane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(all->info.rot_speed)
		- all->player.plane_y * sin(all->info.rot_speed);
	all->player.plane_y = all->ray.oldplane_x * sin(all->info.rot_speed)
		+ all->player.plane_y * cos(all->info.rot_speed);
}
