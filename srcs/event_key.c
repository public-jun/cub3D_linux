/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:29:56 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 19:17:53 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			key_action(t_all *all)
{
	if (all->key.w)
		ft_move_forward(all);
	if (all->key.s)
		ft_move_backward(all);
	if (all->key.d)
		ft_move_right(all);
	if (all->key.a)
		ft_move_left(all);
	if (all->key.right)
		ft_turn_right(all);
	if (all->key.left)
		ft_turn_left(all);
	if (all->key.esc)
		ft_exit(all);
	ft_raycasting(all);
}

void			key_flag_on(int *key, t_all *all)
{
	*key = 1;
	key_action(all);
}

int				key_press(int key, t_all *all)
{
	if (key == K_ESC)
		ft_exit(all);
	else if (key == K_W)
		key_flag_on(&all->key.w, all);
	else if (key == K_A)
		key_flag_on(&all->key.a, all);
	else if (key == K_S)
		key_flag_on(&all->key.s, all);
	else if (key == K_D)
		key_flag_on(&all->key.d, all);
	else if (key == K_RIGHT)
		key_flag_on(&all->key.right, all);
	else if (key == K_LEFT)
		key_flag_on(&all->key.left, all);
	return (0);
}

int				key_release(int key, t_all *all)
{
	if (key == K_ESC)
		ft_exit(all);
	else if (key == K_W)
		all->key.w = 0;
	else if (key == K_A)
		all->key.a = 0;
	else if (key == K_S)
		all->key.s = 0;
	else if (key == K_D)
		all->key.d = 0;
	else if (key == K_RIGHT)
		all->key.right = 0;
	else if (key == K_LEFT)
		all->key.left = 0;
	ft_raycasting(all);
	return (0);
}
