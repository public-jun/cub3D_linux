/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:46:38 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/02 16:18:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parse_line_r(t_all *all, char **line)
{
	char			**tmp;

	if (all->flag.r == 1)
		ft_put_error_and_exit(all, line, "Set only one R\n");
	tmp = ft_split(*line, ' ');
	if (!tmp)
		ft_put_error_and_exit(all, line, "Invalid R format\n");
	if (ft_count_contents(tmp) != 3)
	{
		ft_free_all(tmp);
		ft_put_error_and_exit(all, line, "Invalid R format\n");
	}
	if ((ft_is_all_num(tmp[1]) >= 0) && (ft_is_all_num(tmp[2]) >= 0))
	{
		all->win_r.x = ft_atoi_ex(tmp[1]);
		all->win_r.y = ft_atoi_ex(tmp[2]);
	}
	else
	{
		ft_free_all(tmp);
		ft_put_error_and_exit(all, line, "Invalid R format\n");
	}
	ft_free_all(tmp);
	if (all->win_r.x < 1 || all->win_r.y < 1)
		ft_put_error_and_exit(all, line, "Invalid value\n");
	all->flag.r = 1;
}

void	ft_parse_line_path(t_all *all, char **path,
	int *flag, char **line)
{
	char			*res;
	char			**tmp;

	tmp = NULL;
	res = NULL;
	if (*flag == 1)
		ft_put_error_and_exit(all, line, "Set only one each path\n");
	tmp = ft_split(*line, ' ');
	if (!tmp)
		ft_put_error_and_exit(all, line, "Invalid path format\n");
	if ((ft_count_contents(tmp) != 2) || !(res = ft_strdup(tmp[1])))
	{
		ft_free_all(tmp);
		ft_put_error_and_exit(all, line, "Invalid path format\n");
	}
	ft_free_all(tmp);
	*path = res;
	if (res[0] != '.' || res[1] != '/')
		ft_put_error_and_exit(all, line, "Invalid path\n");
	*flag = 1;
}

static void	ft_input_rgb(t_all *all, char **line,
									t_color *color, char **char_rgb)
{
	if ((ft_is_all_num(char_rgb[R]) >= 0)
		&& (ft_is_all_num(char_rgb[G]) >= 0)
		&& (ft_is_all_num(char_rgb[B]) >= 0))
	{
		color->r = ft_atoi_ex(char_rgb[R]);
		color->g = ft_atoi_ex(char_rgb[G]);
		color->b = ft_atoi_ex(char_rgb[B]);
	}
	else
	{
		ft_free_all(char_rgb);
		ft_put_error_and_exit(all, line,
			"Contains non-numeric characters or Invalid num\n");
	}
	if (color->r < 0 || color->g < 0 || color->b < 0
		|| 255 < color->r || 255 < color->g || 255 < color->b)
	{
		ft_free_all(char_rgb);
		ft_put_error_and_exit(all, line, "Invalid value\n");
	}
}

static int	ft_count_comma(char *dst)
{
	int				res;
	int				i;

	res = 0;
	i = 0;
	while (dst[i])
	{
		if (dst[i] == ',')
			res++;
		i++;
	}
	return (res);
}

void	ft_parse_line_color(t_all *all, t_color *color,
										int *flag, char **line)
{
	char			**char_rgb;
	char			**tmp;

	if (*flag == 1)
		ft_put_error_and_exit(all, line, "Set only one each color\n");
	tmp = NULL;
	if (!(tmp = ft_split(*line, ' ')))
		ft_put_error_and_exit(all, line, "Invalid rgb format\n");
	if ((ft_count_contents(tmp) != 2) || !(char_rgb = ft_split(tmp[1], ',')))
	{
		ft_free_all(tmp);
		ft_put_error_and_exit(all, line, "Invalid rgb format\n");
	}
	if (ft_count_comma(tmp[1]) > 2 || ft_count_contents(char_rgb) != 3)
	{
		ft_free_all(tmp);
		ft_free_all(char_rgb);
		ft_put_error_and_exit(all, line, "Invalid  rgb format\n");
	}
	ft_free_all(tmp);
	ft_input_rgb(all, line, color, char_rgb);
	ft_free_all(char_rgb);
	color->rgb = color->r * 65536 + color->g * 256 + color->b;
	*flag = 1;
}
