/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:42:14 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:13:56 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_set_value_for_draw_sprite(t_all *all,
											t_sprite_info *sp_info, int *i)
{
	sp_info->spr_x = sp_info->order[*i].sp_x - all->player.pos_x;
	sp_info->spr_y = sp_info->order[*i].sp_y - all->player.pos_y;
	sp_info->inv_det = 1.0 / (all->player.plane_x * all->player.dir_y
						- all->player.dir_x * all->player.plane_y);
	sp_info->transform_x = sp_info->inv_det
	* (all->player.dir_y * sp_info->spr_x - all->player.dir_x * sp_info->spr_y);
	sp_info->transform_y = sp_info->inv_det
	* (-all->player.plane_y * sp_info->spr_x
	+ all->player.plane_x * sp_info->spr_y);
	sp_info->spr_screen_x = (int)((all->win_r.x / 2)
						* (1 + sp_info->transform_x / sp_info->transform_y));
}

void			ft_calc_drawing_sprite(t_all *all, t_sprite_info *sp_info)
{
	sp_info->spr_height = (int)ft_abs((all->win_r.y / sp_info->transform_y)
															/ 1.0);
	sp_info->draw_start_y = -sp_info->spr_height / 2 + all->win_r.y / 2;
	if (sp_info->draw_start_y < 0)
		sp_info->draw_start_y = 0;
	sp_info->draw_end_y = sp_info->spr_height / 2 + all->win_r.y / 2;
	if (sp_info->draw_end_y >= all->win_r.y)
		sp_info->draw_end_y = all->win_r.y - 1;
	sp_info->spr_width = (int)ft_abs((all->win_r.y / sp_info->transform_y)
															/ 1.0);
	sp_info->draw_start_x = -sp_info->spr_width / 2 + sp_info->spr_screen_x;
	if (sp_info->draw_start_x < 0)
		sp_info->draw_start_x = 0;
	sp_info->draw_end_x = sp_info->spr_width / 2 + sp_info->spr_screen_x;
	if (sp_info->draw_end_x >= all->win_r.x)
		sp_info->draw_end_x = all->win_r.x - 1;
}

void			ft_set_buf_sprite_tex2(t_all *all, int stripe)
{
	int			y;

	y = all->sprite_info.draw_start_y;
	while (y < all->sprite_info.draw_end_y)
	{
		all->sprite_info.d = (y * 256) - (all->win_r.y * 128)
							+ (all->sprite_info.spr_height * 128);
		all->sprite_info.tex_y =
			((all->sprite_info.d * all->tex.tex_height[SP_TEX])
			/ all->sprite_info.spr_height) / 256;
		if ((0 <= (all->tex.tex_width[SP_TEX]
			* all->sprite_info.tex_y + all->sprite_info.tex_x))
		&& ((all->tex.tex_width[SP_TEX]
			* all->sprite_info.tex_y + all->sprite_info.tex_x)
			< (all->tex.tex_width[SP_TEX] * all->tex.tex_height[SP_TEX])))
			all->sprite_info.color =
				all->info.texture[SP_TEX][all->tex.tex_width[SP_TEX]
				* all->sprite_info.tex_y + all->sprite_info.tex_x];
		else
			all->sprite_info.color = 0x000000;
		if ((all->sprite_info.color & 0xFFFFFF) != 0)
			all->info.buf[y][stripe] = all->sprite_info.color;
		y++;
	}
}

void			ft_set_buf_sprite_tex(t_all *all, t_sprite_info *sp_info)
{
	sp_info->stripe = sp_info->draw_start_x;
	while (sp_info->stripe < sp_info->draw_end_x)
	{
		sp_info->tex_x =
			(int)((256 * (sp_info->stripe
			- (-sp_info->spr_width / 2 + sp_info->spr_screen_x))
			* all->tex.tex_width[SP_TEX] / sp_info->spr_width) / 256);
		if (sp_info->transform_y > 0 && sp_info->stripe > 0
		&& sp_info->stripe < all->win_r.x
		&& sp_info->transform_y < sp_info->zbuffer[sp_info->stripe])
			ft_set_buf_sprite_tex2(all, sp_info->stripe);
		sp_info->stripe++;
	}
}
