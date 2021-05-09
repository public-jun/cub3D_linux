/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:50:17 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/09 16:53:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_and_error_exit(char **tmp, t_all *all, char **line, char *msg)
{
	ft_free_all(tmp);
	ft_put_error_and_exit(all, line, msg);
}
