/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:28:51 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/28 01:19:26 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_is_all_num(char *num)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(num);
	if (len > 1 && num[i] == '0')
		return (-1);
	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (i == len)
		return (0);
	return (-1);
}

int			ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double		ft_abs(double d)
{
	if (d < 0)
		return (-d);
	return (d);
}

double		ft_decimals(double value)
{
	double	ret_decimals;

	ret_decimals = value - (int)value;
	return (ret_decimals);
}

double		ft_floor(double value)
{
	double	ret_int;

	if (value < 0)
	{
		if (value < value - ft_decimals(value))
			ret_int = value - ft_decimals(value) - 1;
		else
			ret_int = (int)value;
	}
	else
		ret_int = (int)value;
	return (ret_int);
}
