/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:01:40 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/07 17:31:22 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	"util_img.h"

# define TRUE	1
# define FALSE	0

# define SCREEN_WIDTH		1920
# define SCREEN_HEIGHT		1080
# define MOVE_SPEED			0.05
# define ROTATE_SPEED		0.05
# define MOUSE_ROTATE_SPEED	0.02

typedef struct s_vector{
	double	x;
	double	y;
}	t_vector;

typedef struct s_textures_img{
	t_img	background;
	t_img	full_minimap;
	t_img	minimap;
	t_img	wall_ea;
	t_img	wall_we;
	t_img	wall_so;
	t_img	wall_no;
	t_img	ceiling;
	t_img	floor;
}	t_textures_img;

typedef struct s_textures_info{
	char			*wall_ea_file_name;
	char			*wall_we_file_name;
	char			*wall_so_file_name;
	char			*wall_no_file_name;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
}	t_textures_info;

typedef struct s_minimap_info{
	int				block_size;
	unsigned int	floor_color;
	unsigned int	wall_color;
	unsigned int	empty_color;
	unsigned int	player_color;
}	t_minimap_info;

typedef struct s_map{
	char			**data;
	unsigned int	width;
	unsigned int	height;
}	t_map;

typedef struct s_window{
	void	*win;
	int		width;
	int		height;
}	t_window;

typedef struct s_player{
	t_vector	pos;
	t_vector	plane;
	t_vector	dir;
}	t_player;

typedef struct s_cub3d_info{
	int						mouse;
	void					*mlx;
	void					*window;
	t_map					map;
	t_player				player;
	t_textures_img			textures;
	t_textures_info			textures_info;
	t_minimap_info			minimap_info;
}	t_cub3d_info;

#endif
