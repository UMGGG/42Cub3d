/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:00:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 16:19:11 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"
# include "ray_cast.h"

typedef struct s_bresenham_info
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	dx;
	int	dy;
	int	stepx;
	int	stepy;
	int	fraction;
}	t_bresenham_info;

int		init_minimap_img(t_cub3d_info *info, t_map *map);
void	draw_minimap(t_cub3d_info *info);
void	draw_fov_on_minimap(t_cub3d_info *info, t_ray_info *ray_info);

#endif
