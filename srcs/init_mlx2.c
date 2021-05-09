/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:30:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/09 16:32:48 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_key_init(t_all *all)
{
	all->key.a = 0;
	all->key.w = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.esc = 0;
	all->key.left = 0;
	all->key.right = 0;
}

void	ft_resize_win(t_all *all)
{
	if (all->save == 0)
	{
		if (all->win_r.x > all->win_r.screen_x)
			all->win_r.x = all->win_r.screen_x;
		if (all->win_r.y > all->win_r.screen_y)
			all->win_r.y = all->win_r.screen_y;
	}
}
