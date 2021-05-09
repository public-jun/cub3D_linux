/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:26:50 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/05 15:31:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_direction_tex(t_all *all)
{
	if (all->ray.raydir_y > 0 && all->ray.side == 1)
		all->tex.num = S_TEX;
	else if (all->ray.raydir_y < 0 && all->ray.side == 1)
		all->tex.num = N_TEX;
	else if (all->ray.raydir_x > 0 && all->ray.side == 0)
		all->tex.num = E_TEX;
	else if (all->ray.raydir_x < 0 && all->ray.side == 0)
		all->tex.num = W_TEX;
	else
		all->tex.num = -1;
}

void	ft_attach_tex_size_for_screen(t_all *all, t_tex *tex)
{
	all->ray.wall_x = 0;
	if (all->ray.side == 0)
		all->ray.wall_x = all->player.pos_y
			+ all->ray.prepwalldist * all->ray.raydir_y;
	else
		all->ray.wall_x = all->player.pos_x
			+ all->ray.prepwalldist * all->ray.raydir_x;
	all->ray.wall_x -= ft_floor(all->ray.wall_x);
	all->tex.tex_x = (int)(all->ray.wall_x
			* (double)all->tex.tex_width[tex->num]);
	if (all->ray.side == 0 && all->ray.raydir_x > 0)
		all->tex.tex_x = all->tex.tex_width[tex->num] - all->tex.tex_x - 1;
	if (all->ray.side == 1 && all->ray.raydir_y < 0)
		all->tex.tex_x = all->tex.tex_width[tex->num] - all->tex.tex_x - 1;
	all->tex.step = 1.0 * all->tex.tex_height[tex->num] / all->ray.lineheight;
	all->tex.texpos = (all->ray.drawstart - all->win_r.y / 2
			+ all->ray.lineheight / 2) * all->tex.step;
}

void	ft_set_buf(t_all *all, int x)
{
	int			y;
	int			color;

	y = all->ray.drawstart;
	color = 0;
	while (y < all->ray.drawend)
	{
		all->tex.tex_y = ft_min((int)all->tex.texpos,
				all->tex.tex_height[all->tex.num] - 1);
		all->tex.texpos += all->tex.step;
		color = all->info.texture[all->tex.num]
		[(all->tex.tex_width[all->tex.num])
			*(all->tex.tex_y) + all->tex.tex_x];
		all->info.buf[y][x] = color;
		y++;
	}
	all->sprite_info.zbuffer[x] = all->ray.prepwalldist;
}
