/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:21:20 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/09 16:41:41 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_buf(t_all *all, int height, int width)
{
	int			i;
	int			j;

	all->info.buf = (int **)malloc(sizeof(int *) * height);
	if (!all->info.buf)
		ft_put_error_and_exit(all, NULL, "Can't malloc in ft_init_buf\n");
	i = 0;
	while (i < all->win_r.y)
	{
		all->info.buf[i++] = (int *)malloc(sizeof(int) * width);
		if (!all->info.buf[i++])
			ft_put_error_and_exit(all, NULL, "Can't malloc in ft_init_buf\n");
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			all->info.buf[i][j++] = 0;
		i++;
	}
}

void	ft_init_texture_and_zbuffer(t_all *all)
{
	int			i;

	all->info.texture = (int **)malloc(sizeof(int *) * 5);
	if (!all->info.texture)
		ft_put_error_and_exit(all, NULL, "Can't malloc in ft_init_texture\n");
	i = 0;
	while (i < 5)
		all->info.texture[i++] = NULL;
	all->sprite_info.zbuffer = (double *)malloc(sizeof(double) * all->win_r.x);
	if (!all->sprite_info.zbuffer)
		ft_put_error_and_exit(all, NULL, "cant malloc in ft_init_zbuffer");
	i = 0;
	while (i < all->win_r.x)
		all->sprite_info.zbuffer[i++] = 0;
}

static void	ft_mlx_init(t_all *all)
{
	if (all->save == 0)
	{
		all->info.win = mlx_new_window(all->info.mlx,
				all->win_r.x, all->win_r.y, "cub3d");
		if (!all->info.win)
			ft_put_error_and_exit(all, NULL, "mlx_new_window failed\n");
	}
	all->info.img.img_ptr = mlx_new_image(all->info.mlx,
			all->win_r.x, all->win_r.y);
	if (!all->info.img.img_ptr)
		ft_put_error_and_exit(all, NULL, "mlx_new_image failed\n");
	all->info.img.data = (int *)mlx_get_data_addr(all->info.img.img_ptr,
			&all->info.img.bpp, &all->info.img.size_l, &all->info.img.endian);
	if (!all->info.img.data)
		ft_put_error_and_exit(all, NULL, "mlx_get_data_addr failed\n");
}

void	ft_mlx_and_raycast_init(t_all *all)
{
	all->info.mlx = mlx_init();
	if (!all->info.mlx)
		ft_put_error_and_exit(all, NULL, "mlx_init failed\n");
	mlx_get_screen_size(all->info.mlx, &all->win_r.screen_x,
		&all->win_r.screen_y);
	ft_resize_win(all);
	ft_key_init(all);
	ft_init_texture_and_zbuffer(all);
	ft_load_texture(all);
	ft_mlx_init(all);
	all->flag.mlx_start = 1;
	ft_init_buf(all, all->win_r.y, all->win_r.x);
}
