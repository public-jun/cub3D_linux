/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:22:17 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 22:26:30 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_window_to_save(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->win_r.y)
	{
		x = 0;
		while (x < all->win_r.x)
		{
			all->info.img.data[all->win_r.x * y + x]
				= all->info.buf[all->win_r.y - 1 - y][x];
			x++;
		}
		y++;
	}
}

void	ft_write_bmp_header(t_all *all, int fd, int filesize)
{
	unsigned char	fileheader[54];

	ft_bzero(fileheader, 54);
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(54);
	fileheader[14] = (unsigned char)(40);
	fileheader[18] = (unsigned char)(all->win_r.x);
	fileheader[19] = (unsigned char)(all->win_r.x >> 8);
	fileheader[20] = (unsigned char)(all->win_r.x >> 16);
	fileheader[21] = (unsigned char)(all->win_r.x >> 24);
	fileheader[22] = (unsigned char)(all->win_r.y);
	fileheader[23] = (unsigned char)(all->win_r.y >> 8);
	fileheader[24] = (unsigned char)(all->win_r.y >> 16);
	fileheader[25] = (unsigned char)(all->win_r.y >> 24);
	fileheader[26] = (unsigned char)(1);
	fileheader[28] = (unsigned char)(32);
	write(fd, fileheader, 54);
}

void	ft_make_bmp(t_all *all)
{
	int	filesize;
	int	fd;

	filesize = 54 + (4 * all->win_r.x * all->win_r.y);
	fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0)
		ft_put_error_and_exit(all, NULL, "Can't cretate bmp\n");
	ft_write_bmp_header(all, fd, filesize);
	write(fd, (char *)all->info.img.data, 4 * all->win_r.x * all->win_r.y);
	close(fd);
}

void				ft_write_bmp(t_all *all)
{
	floor_and_ceilling_casting(all);
	ft_wall_casting(all);
	ft_sprite_casting(all);
	ft_draw_window_to_save(all);
	ft_make_bmp(all);
	ft_exit(all);
}
