/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:49:30 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:03:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_sprite_distance(t_all *all, t_sprite *order)
{
	int			i;

	i = 0;
	while (i < all->sprite_info.num)
	{
		all->sprite_info.order[i].distance = \
		((all->player.pos_x - order[i].sp_x) \
		* (all->player.pos_x - order[i].sp_x) \
		+ (all->player.pos_y - order[i].sp_y) \
		* (all->player.pos_y - order[i].sp_y));
		i++;
	}
}

void	ft_sort_sprites(t_sprite_info *sp_info)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < sp_info->num)
	{
		j = 0;
		while (j < sp_info->num - 1)
		{
			if (sp_info->order[j].distance < sp_info->order[j + 1].distance)
			{
				tmp = sp_info->order[j];
				sp_info->order[j] = sp_info->order[j + 1];
				sp_info->order[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sprite_casting(t_all *all)
{
	int			i;

	ft_set_sprite_distance(all, all->sprite_info.order);
	ft_sort_sprites(&all->sprite_info);
	i = 0;
	while (i < all->sprite_info.num)
	{
		ft_set_value_for_draw_sprite(all, &all->sprite_info, &i);
		ft_calc_drawing_sprite(all, &all->sprite_info);
		ft_set_buf_sprite_tex(all, &all->sprite_info);
		i++;
	}
}
