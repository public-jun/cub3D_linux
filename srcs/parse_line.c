/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:36:53 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 23:31:59 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_flag_on_expect_map(t_all *all)
{
	if (all->flag.r == 1 && all->flag.no == 1 && all->flag.so == 1
		&& all->flag.we == 1 && all->flag.ea == 1 && all->flag.s == 1
		&& all->flag.f == 1 && all->flag.c == 1)
		return (1);
	else
		return (0);
}

int				ft_skip_null_and_space(char **line, int *i)
{
	if (!(*line)[*i])
		return (-1);
	while ((*line)[*i] == ' ')
		(*i)++;
	if (!(*line)[*i])
		return (-1);
	return (0);
}

void			ft_judge_element(t_all *all, char **line, int *i)
{
	if ((*line)[*i] == 'R' && (*line)[*i + 1] == ' ')
		ft_parse_line_r(all, line);
	else if ((*line)[*i] == 'N' && (*line)[*i + 1] == 'O'
		&& (*line)[*i + 2] == ' ')
		ft_parse_line_path(all, &all->path_tex.north, &all->flag.no, line);
	else if ((*line)[*i] == 'S' && (*line)[*i + 1] == 'O'
		&& (*line)[*i + 2] == ' ')
		ft_parse_line_path(all, &all->path_tex.south, &all->flag.so, line);
	else if ((*line)[*i] == 'W' && (*line)[*i + 1] == 'E'
		&& (*line)[*i + 2] == ' ')
		ft_parse_line_path(all, &all->path_tex.west, &all->flag.we, line);
	else if ((*line)[*i] == 'E' && (*line)[*i + 1] == 'A'
		&& (*line)[*i + 2] == ' ')
		ft_parse_line_path(all, &all->path_tex.east, &all->flag.ea, line);
	else if ((*line)[*i] == 'S' && (*line)[*i + 1] == ' ')
		ft_parse_line_path(all, &all->path_tex.sprite, &all->flag.s, line);
	else if ((*line)[*i] == 'F' && (*line)[*i + 1] == ' ')
		ft_parse_line_color(all, &all->color_f, &all->flag.f, line);
	else if ((*line)[*i] == 'C' && (*line)[*i + 1] == ' ')
		ft_parse_line_color(all, &all->color_c, &all->flag.c, line);
}

void			ft_parse_line_param(t_all *all, char **line)
{
	int			i;

	i = 0;
	if (ft_skip_null_and_space(line, &i) == -1)
		return ;
	if ((ft_strncmp((*line + i), "NO ", 3)) && (ft_strncmp((*line + i), "SO ", 3)) && (ft_strncmp((*line + i), "WE ", 3)) && (ft_strncmp((*line + i), "EA ", 3)) && (ft_strncmp((*line + i), "S ", 2)) && (ft_strncmp((*line + i), "C ", 3)) && (ft_strncmp((*line + i), "C ", 3)))
		ft_put_error_and_exit(all, NULL, "This element is invalid\n");
	ft_judge_element(all, line, &i);
}

void			ft_parse_line(t_all *all, char **line)
{
	if (all->map.cont < 0 && (*line)[0] != '\0')
		ft_put_error_and_exit(all, line, "map is not end\n");
	if (all->flag.except_map == 0)
		ft_parse_line_param(all, line);
	if (all->flag.except_map == 1)
		ft_parse_line_map(all, line);
	if (all->flag.except_map == 0)
		all->flag.except_map = ft_flag_on_expect_map(all);
}
