# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 16:49:55 by jnakahod          #+#    #+#              #
#    Updated: 2021/05/09 16:50:39 by jnakahod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

LIBS = -lXext -lX11
MLX_DIR = ./minilibx-linux

SRCS = srcs/cub3d.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/init.c \
		srcs/init2.c \
		srcs/exit.c \
		srcs/parse_line.c \
		srcs/parse_element.c \
		srcs/parse_element2.c \
		srcs/parse_map.c \
		srcs/parse_map2.c \
		srcs/flood_fill.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/get_info_from_map.c \
		srcs/set_player_info.c \
		srcs/load_texture.c \
		srcs/init_mlx.c \
		srcs/init_mlx2.c \
		srcs/event_key.c \
		srcs/move.c \
		srcs/turn.c \
		srcs/ray_casting.c \
		srcs/floor_and_ceilling_casting.c \
		srcs/wall_casting.c \
		srcs/wall_casting2.c \
		srcs/sprite_casting.c \
		srcs/sprite_casting2.c \
		srcs/bmp.c \

OBJCS = $(SRCS:%.c=%.o)

INCLUDE = ./includes

RM = rm -f

all: $(NAME)

$(NAME): $(OBJCS)
		$(MAKE) -C $(LIBFT_DIR) bonus
		$(MAKE) -C $(MLX_DIR)
		cp $(MLX_DIR)/libmlx_Linux.a .
		$(CC) $(CFLAGS) $(OBJCS) -L. -Lminilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME)
clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		$(RM) $(OBJCS) cub3d.bmp

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJCS)
		$(RM) $(NAME) ./libmlx_Linux.a ./cu3d.bmp

re: fclean all

test:
		$(CC) -g $(SRCS) -L. -Lminilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re test
