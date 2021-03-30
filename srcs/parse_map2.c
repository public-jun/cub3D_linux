/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:19:12 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/27 16:22:11 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_store_line_with_map(t_all *all, char **line)
{
	int			x;

	x = 0;
	while ((x + 1 < MAP_WIDTH - 1) && ((*line)[x] != '\0'))
	{
		if ((*line)[x] == ' ')
			(*line)[x] = '0';
		all->map.char_map[all->map.tmp_y][x + 1] = (*line)[x];
		x++;
	}
	all->map.tmp_y++;
}

void			ft_judge_possible_chars(t_all *all, char **line)
{
	int			i;

	i = 0;
	while ((*line)[i])
	{
		if (((*line)[i] == 'N' || (*line)[i] == 'S' || (*line)[i] == 'W'
			|| (*line)[i] == 'E') && all->map.pflag == 1)
			ft_put_error_and_exit(all, line,
				"Set only one player coordinates\n");
		if (!((*line)[i] == ' ' || (*line)[i] == '0' || (*line)[i] == '1'
			|| (*line)[i] == '2' || (*line)[i] == 'N' || (*line)[i] == 'S'
			|| (*line)[i] == 'W' || (*line)[i] == 'E'))
			ft_put_error_and_exit(all, line,
				"The map is be composed of inpossible characters\n");
		if ((*line)[i] == 'N' || (*line)[i] == 'S'
			|| (*line)[i] == 'W' || (*line)[i] == 'E')
			all->map.pflag = 1;
		i++;
	}
}

int				ft_in_the_process_of_forming_map(t_all *all, char **line)
{
	if ((*line)[0] == '\0' && all->map.cont == 0)
		return (-1);
	else if ((*line)[0] == '\0' && all->map.cont == 1)
	{
		all->map.cont = -1;
		return (-1);
	}
	if (all->map.cont == 0)
	{
		all->map.cont = 1;
		return (1);
	}
	return (0);
}
