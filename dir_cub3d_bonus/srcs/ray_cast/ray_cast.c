/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:52:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:45 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"ray_cast.h"
#include	"math.h"
#include	"mlx.h"
#include	"util_init.h"
#include	"minimap.h"

void	ray_cast(t_cub3d_info *info)
{
	t_vector	screen;
	t_ray_info	ray_info;

	screen.x = 0;
	init_background_img(&info->textures.background,
		info->textures_info.ceiling_color, info->textures_info.floor_color);
	draw_minimap(info);
	while (screen.x < SCREEN_WIDTH)
	{
		init_ray_info(info, &ray_info, screen.x);
		calc_first_ray_dist(info, &ray_info);
		check_ray_hit(info, &ray_info);
		calc_wall_height(info, &ray_info);
		ver_line_each_side(info, &ray_info, &screen);
		draw_fov_on_minimap(info, &ray_info);
		++screen.x;
	}
	mlx_put_image_to_window(info->mlx, info->window, \
							info->textures.background.img_ptr, 0, 0);
	mlx_put_image_to_window(info->mlx, info->window, \
							info->textures.minimap.img_ptr, 25, 25);
}

void	init_ray_info(t_cub3d_info *info, t_ray_info *ray_info, int x)
{
	ray_info->is_door = FALSE;
	ray_info->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray_info->raydir.x = info->player.dir.x + \
						info->player.plane.x * ray_info->camera_x;
	ray_info->raydir.y = info->player.dir.y + \
						info->player.plane.y * ray_info->camera_x;
	ray_info->ray.x = (int)info->player.pos.x;
	ray_info->ray.y = (int)info->player.pos.y;
	ray_info->second_dist.x = fabs(1 / ray_info->raydir.x);
	ray_info->second_dist.y = fabs(1 / ray_info->raydir.y);
}

void	calc_first_ray_dist(t_cub3d_info *info, t_ray_info *ray_info)
{
	if (ray_info->raydir.x < 0)
	{
		ray_info->ray_move_dir.x = -1;
		ray_info->first_dist.x = (info->player.pos.x - ray_info->ray.x) \
									* ray_info->second_dist.x;
	}
	else
	{
		ray_info->ray_move_dir.x = 1;
		ray_info->first_dist.x = (ray_info->ray.x + 1.0 - info->player.pos.x) \
									* ray_info->second_dist.x;
	}
	if (ray_info->raydir.y < 0)
	{
		ray_info->ray_move_dir.y = -1;
		ray_info->first_dist.y = (info->player.pos.y - ray_info->ray.y) \
									* ray_info->second_dist.y;
	}
	else
	{
		ray_info->ray_move_dir.y = 1;
		ray_info->first_dist.y = (ray_info->ray.y + 1.0 - info->player.pos.y) \
									* ray_info->second_dist.y;
	}
}

void	check_ray_hit(t_cub3d_info *info, t_ray_info *ray_info)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (ray_info->first_dist.x < ray_info->first_dist.y)
		{
			ray_info->first_dist.x += ray_info->second_dist.x;
			ray_info->ray.x += ray_info->ray_move_dir.x;
			ray_info->is_side = FALSE;
		}
		else
		{
			ray_info->first_dist.y += ray_info->second_dist.y;
			ray_info->ray.y += ray_info->ray_move_dir.y;
			ray_info->is_side = TRUE;
		}
		if (info->map.data[(int)ray_info->ray.y][(int)ray_info->ray.x] == '1')
			hit = TRUE;
		if (info->map.data[(int)ray_info->ray.y][(int)ray_info->ray.x] == '2')
		{
			hit = TRUE;
			ray_info->is_door = TRUE;
		}
	}
}
