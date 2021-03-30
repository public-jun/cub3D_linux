/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:29:56 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 20:03:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				key_press(int key, t_all *all)
{
	if (key == K_ESC)
		ft_exit(all);
	else if (key == K_W)
		ft_move_forward(all);
	else if (key == K_A)
		ft_move_left(all);
	else if (key == K_S)
		ft_move_backward(all);
	else if (key == K_D)
		ft_move_right(all);
	else if (key == K_RIGHT)
		ft_turn_right(all);
	else if (key == K_LEFT)
		ft_turn_left(all);
	ft_raycasting(all);
	return (0);
}

// int				key_release(int key, t_all *all)
// {
// 	if (key == K_ESC)
// 		ft_exit(all);
// 	else if (key == K_W)
// 		all->key.w = 0;
// 	else if (key == K_A)
// 		all->key.a = 0;
// 	else if (key == K_S)
// 		all->key.s = 0;
// 	else if (key == K_D)
// 		all->key.d = 0;
// 	else if (key == K_RIGHT)
// 		all->key.right = 0;
// 	else if (key == K_LEFT)
// 		all->key.left = 0;
// 	return (0);
// }
