/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:23:19 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/28 16:22:30 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_free_path(t_all *all)
{
	if (all->path_tex.north)
		free(all->path_tex.north);
	if (all->path_tex.south)
		free(all->path_tex.south);
	if (all->path_tex.west)
		free(all->path_tex.west);
	if (all->path_tex.east)
		free(all->path_tex.east);
	if (all->path_tex.sprite)
		free(all->path_tex.sprite);
}

void		free_set_int(int **dst, int *src)
{
	free(*dst);
	*dst = src;
}

void		ft_free_double_int_p(int **dst, int size)
{
	int		i;

	i = 0;
	if (dst != NULL)
	{
		while (i < size)
		{
			free_set_int(&dst[i], NULL);
			i++;
		}
		free(dst);
	}
}

int			ft_exit(t_all *all)
{
	ft_free_path(all);
	if (all->sprite_info.order)
		free(all->sprite_info.order);
	if (all->flag.mlx_start == 1)
	{
		if (all->save == 0 && all->info.win)
			mlx_destroy_window(all->info.mlx, all->info.win);
		if (all->info.img.img_ptr)
			mlx_destroy_image(all->info.mlx, all->info.img.img_ptr);
		if (all->info.mlx)
		{
			mlx_destroy_display(all->info.mlx);
			free(all->info.mlx);
		}
		ft_free_double_int_p(all->info.buf, all->win_r.y);
	}
	if (all->info.texture)
		ft_free_double_int_p(all->info.texture, 5);
	if (all->sprite_info.zbuffer)
		free(all->sprite_info.zbuffer);
	exit(0);
}

void		ft_put_error_and_exit(t_all *all, char **line, char *s)
{
	write(1, "\e[31mError\e[m\n", 15);
	ft_putstr_fd(s, 2);
	if (line)
	{
		get_next_line(all->fd, NULL);
		free(*line);
	}
	ft_exit(all);
}
