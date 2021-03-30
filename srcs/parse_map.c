/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:19:44 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:23:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_count_sprite(t_all *all, char **line)
{
	int			i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '2')
			all->sprite_info.num++;
		i++;
	}
}

void			ft_parse_line_map(t_all *all, char **line)
{
	if (ft_in_the_process_of_forming_map(all, line) >= 0)
	{
		ft_judge_possible_chars(all, line);
		if ((MAP_WIDTH - 2 < (int)ft_strlen(*line))
			|| (MAP_HEIGHT - 2 < all->map.tmp_y))
			ft_put_error_and_exit(all, line,
				"Map size limits is exceeded\n");
		ft_count_sprite(all, line);
		ft_store_line_with_map(all, line);
	}
}
