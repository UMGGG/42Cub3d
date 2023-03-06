/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_door_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:08:56 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/06 16:18:13 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_action.h"
#include	"cub3d.h"
#include	"ray_cast.h"

static void	break_door(t_cub3d_info *info);
static void	upadate_minimap(t_cub3d_info *info, t_vector ray, \
															unsigned int color);
static void	check_ray_hit_door(t_cub3d_info *info, t_ray_info *ray_info);

int	key_pressed_space(int key, t_cub3d_info *info)
{
	if (key == KEY_SPACE)
		break_door(info);
	return (0);
}

static void	break_door(t_cub3d_info *info)
{
	t_ray_info	ray_info;

	init_ray_info(info, &ray_info, SCREEN_WIDTH / 2);
	calc_first_ray_dist(info, &ray_info);
	check_ray_hit_door(info, &ray_info);
	calc_wall_height(info, &ray_info);
	if (ray_info.wall_dist <= 0.9f)
	{
		if (info->map.data[(int)ray_info.ray.y][(int)ray_info.ray.x] == '2')
		{
			info->map.data[(int)ray_info.ray.y][(int)ray_info.ray.x] = '3';
			upadate_minimap(info, ray_info.ray, \
										info->minimap_info.opened_door_color);
			return ;
		}
		if (info->map.data[(int)ray_info.ray.y][(int)ray_info.ray.x] == '3')
		{
			info->map.data[(int)ray_info.ray.y][(int)ray_info.ray.x] = '2';
			upadate_minimap(info, ray_info.ray, info->minimap_info.door_color);
		}
	}
}

static void	upadate_minimap(t_cub3d_info *info, t_vector ray, \
															unsigned int color)
{
	t_vector	pos;
	t_vector	end;
	char		*addr;

	pos.x = (int)ray.x * info->minimap_info.block_size;
	pos.y = (int)ray.y * info->minimap_info.block_size;
	end.x = pos.x + info->minimap_info.block_size;
	end.y = pos.y + info->minimap_info.block_size;
	while (pos.y < end.y)
	{
		pos.x = (int)ray.x * info->minimap_info.block_size;
		while (pos.x < end.x)
		{
			addr = get_pixel_addr_img(&info->textures.full_minimap, \
															pos.x, pos.y);
			*(unsigned int *)addr = color;
			++pos.x;
		}
		++pos.y;
	}
}

static void	check_ray_hit_door(t_cub3d_info *info, t_ray_info *ray_info)
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
		if ((info->map.data[(int)ray_info->ray.y][(int)ray_info->ray.x] == '1') \
		|| (info->map.data[(int)ray_info->ray.y][(int)ray_info->ray.x] == '2') \
		|| (info->map.data[(int)ray_info->ray.y][(int)ray_info->ray.x] == '3'))
			hit = TRUE;
	}
}
