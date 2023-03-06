/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:36:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/02 20:19:58 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# include "cub3d.h"

typedef struct s_ray_info
{
	t_vector	ray;
	t_vector	ray_move_dir;
	t_vector	raydir;
	t_vector	first_dist;
	t_vector	second_dist;
	int			is_side;
	int			is_door;
	int			draw_start;
	int			draw_end;
	double		camera_x;
	double		wall_dist;
	double		wall_height;
}	t_ray_info;

void	ray_cast(t_cub3d_info *info);
int		ray_loop(t_cub3d_info *info);
void	calc_wall_height(t_cub3d_info *info, t_ray_info *ray_info);
void	ver_line_each_side(t_cub3d_info *info, t_ray_info *ray_info, \
														t_vector *screen);
void	ver_line(t_cub3d_info *info, t_ray_info *ray_info, t_vector *screen, \
															t_img *texture);
void	init_ray_info(t_cub3d_info *info, t_ray_info *ray_info, int x);
void	calc_first_ray_dist(t_cub3d_info *info, t_ray_info *ray_info);
void	check_ray_hit(t_cub3d_info *info, t_ray_info *ray_info);

int		is_wall_south_side(t_ray_info *ray_info);
int		is_wall_north_side(t_ray_info *ray_info);
int		is_wall_east_side(t_ray_info *ray_info);
int		is_wall_west_side(t_ray_info *ray_info);

#endif
