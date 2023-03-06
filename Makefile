# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:27:03 by jiwolee           #+#    #+#              #
#    Updated: 2023/02/09 17:11:14 by jiwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

BONUS		= cub3D_bonus

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
MLX_DIR		= ./mlx

LIBFT_DIR	= ./libft_for_cub3d

HEADER		= ./dir_cub3d/includes
INCLUDES	= -I$(HEADER) -I$(MLX_DIR) -I$(LIBFT_DIR)

HEADER_BONUS = ./dir_cub3d_bonus/includes
INCLUDES_BONUS = -I$(HEADER_BONUS) -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC_1		= ./dir_cub3d/srcs/cub3d.c \
			  ./dir_cub3d/srcs/utils/util_img.c \
			  ./dir_cub3d/srcs/utils/util_error.c \
			  ./dir_cub3d/srcs/init_map/util_init_map.c\
			  ./dir_cub3d/srcs/init_map/check_mapfile_info.c \
			  ./dir_cub3d/srcs/init_map/check_mapfile_map.c \
			  ./dir_cub3d/srcs/init_map/init_type_info1.c \
			  ./dir_cub3d/srcs/init_map/init_type_info2.c \
			  ./dir_cub3d/srcs/init_map/init_type_info3.c \
			  ./dir_cub3d/srcs/init_map/read_save_map.c \
			  ./dir_cub3d/srcs/init_map/check_mapfile_valid.c \
			  ./dir_cub3d/srcs/init/init_mlx.c \
			  ./dir_cub3d/srcs/init/init_imgs.c \
			  ./dir_cub3d/srcs/ray_cast/ray_cast.c \
			  ./dir_cub3d/srcs/ray_cast/ray_cast2.c \
			  ./dir_cub3d/srcs/ray_cast/check_wall.c\
			  ./dir_cub3d/srcs/utils/util_color.c \
			  ./dir_cub3d/srcs/utils/util_safe_libft.c \
			  ./dir_cub3d/srcs/util_action/get_key_action.c \
			  ./dir_cub3d/srcs/util_action/move_rotate_player.c \
			  ./dir_cub3d/srcs/util_action/get_mouse_action.c \
			  ./dir_cub3d/srcs/minimap/init_minimap_img.c \
			  ./dir_cub3d/srcs/minimap/draw_minimap.c \
			  ./dir_cub3d/srcs/minimap/draw_fov_on_minimap.c

SRC_2		= ./gnl_for_cub3d/get_next_line.c\
			  ./gnl_for_cub3d/get_next_line_utils.c

SRC_BONUS	= ./dir_cub3d_bonus/srcs/cub3d.c \
			  ./dir_cub3d_bonus/srcs/utils/util_img.c \
			  ./dir_cub3d_bonus/srcs/utils/util_error.c \
			  ./dir_cub3d_bonus/srcs/init_map/util_init_map.c\
			  ./dir_cub3d_bonus/srcs/init_map/check_mapfile_info.c \
			  ./dir_cub3d_bonus/srcs/init_map/check_mapfile_map.c \
			  ./dir_cub3d_bonus/srcs/init_map/init_type_info1.c \
			  ./dir_cub3d_bonus/srcs/init_map/init_type_info2.c \
			  ./dir_cub3d_bonus/srcs/init_map/init_type_info3.c \
			  ./dir_cub3d_bonus/srcs/init_map/read_save_map.c \
			  ./dir_cub3d_bonus/srcs/init_map/check_mapfile_valid.c \
			  ./dir_cub3d_bonus/srcs/init/init_mlx.c \
			  ./dir_cub3d_bonus/srcs/init/init_imgs.c \
			  ./dir_cub3d_bonus/srcs/ray_cast/ray_cast.c \
			  ./dir_cub3d_bonus/srcs/ray_cast/ray_cast2.c \
			  ./dir_cub3d_bonus/srcs/ray_cast/check_wall.c\
			  ./dir_cub3d_bonus/srcs/utils/util_color.c \
			  ./dir_cub3d_bonus/srcs/utils/util_safe_libft.c \
			  ./dir_cub3d_bonus/srcs/util_action/get_key_action.c \
			  ./dir_cub3d_bonus/srcs/util_action/move_rotate_player.c \
			  ./dir_cub3d_bonus/srcs/util_action/get_mouse_action.c \
			  ./dir_cub3d_bonus/srcs/util_action/break_door_action.c \
			  ./dir_cub3d_bonus/srcs/minimap/init_minimap_img.c \
			  ./dir_cub3d_bonus/srcs/minimap/draw_minimap.c \
			  ./dir_cub3d_bonus/srcs/minimap/draw_fov_on_minimap.c

SRCS		= $(SRC_1) $(SRC_2)

SRCS_BONUS	= $(SRC_BONUS) $(SRC_2)

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} $(INCLUDES) -c -o $@ $^

%.o : %.c
		${CC} ${CFLAGS} $(INCLUDES_BONUS) -c -o $@ $^

$(NAME) : $(OBJS)
		make -C $(MLX_DIR)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAG) $(INCLUDES) -o $@ $^ -L $(MLX_DIR) $(MLX_FLAGS) -L $(LIBFT_DIR) -lft

$(BONUS) : $(OBJS_BONUS)
		make -C $(MLX_DIR)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAG) $(INCLUDES_BONUS) -o $@ $^ -L $(MLX_DIR) $(MLX_FLAGS) -L $(LIBFT_DIR) -lft

all : $(NAME) $(BONUS)

bonus : $(BONUS)

clean :
		rm -f $(OBJS) $(OBJS_BONUS)
		make $@ -C $(MLX_DIR)
		make $@ -C $(LIBFT_DIR)

fclean : clean
		make $@ -C $(LIBFT_DIR)
		rm -f $(NAME)
		rm -f $(BONUS)

re : fclean $(NAME)

re_all : fclean all

PHONY : all clean fclean re bonus re_all
