/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:52:47 by jnakahod          #+#    #+#             */
/*   Updated: 2021/03/30 12:36:51 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_FD 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
int				fd_read(int *flag, int fd, char **line, char **save);
char			*ft_strjoin_n(char *s1, char *s2, size_t n);
size_t			ft_strchr_ex(char *s, int c);
int				put_line(char **line, char **save, char *buf);
int				get_next_line(int fd, char **line);
#endif
