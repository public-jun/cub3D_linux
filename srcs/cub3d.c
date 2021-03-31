/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:03:09 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/31 16:49:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_read_cub(t_all *all)
{
	int			res;
	char		*line;

	line = NULL;
	res = 0;
	while ((res = get_next_line(all->fd, &line)) > 0)
	{
		ft_parse_line(all, &line);
		free(line);
	}
	if (res == 0 && all->flag.except_map == 0)
		ft_put_error_and_exit(all, &line, "This cub file is insufficient\n");
	if (res == -1)
		ft_put_error_and_exit(all, &line, "Failed to read\n");
	free(line);
}

static int		ft_iscub(char *cub)
{
	int			len;

	len = (int)ft_strlen(cub);
	if (len > 4 && cub[len - 5] == '/' && cub[len - 4] == '.'
		&& cub[len - 3] == 'c' && cub[len - 2] == 'u' && cub[len - 1] == 'b')
		return (0);
	if (len > 4 && cub[len - 4] == '.' && cub[len - 3] == 'c'
		&& cub[len - 2] == 'u' && cub[len - 1] == 'b')
		return (1);
	return (0);
}

int			focus_in(t_all *all)
{
	floor_and_ceilling_casting(all);
	ft_wall_casting(all);
	ft_sprite_casting(all);
	ft_draw_to_window(all);
	return (0);
}

int				main(int ac, char **av)
{
	t_all		all;
	int			fd;

	fd = 0;
	if ((ac == 2 && ft_iscub(av[1]))
		|| (ac == 3 && ft_iscub(av[1]) && !ft_strncmp(av[2], "--save", 7)))
	{
		ft_init(&all, ac);
		if ((all.fd = open(av[1], O_RDONLY)) < 0)
			ft_put_error_and_exit(&all, NULL, "Failed to open\n");
		ft_read_cub(&all);
		ft_set_data_for_raycast(&all);
		ft_flood_fill(&all, all.map.char_r_map, all.map.p_x, all.map.p_y);
		close(fd);
		ft_mlx_and_raycast_init(&all);
		if (ac == 3)
			ft_write_bmp(&all);
		focus_in(&all);
		mlx_hook(all.info.win, 2, 1L << 0, &key_press, &all);
		mlx_hook(all.info.win, 33, 1L << 17, &ft_exit, &all);
		mlx_hook(all.info.win, 9, 1 << 21, &focus_in, &all);
		mlx_loop(all.info.mlx);
	}
	ft_put_error_and_exit(&all, NULL, "Invalid comandline arguments\n");
}
