/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:35 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 17:34:07 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ray_cast.h"
#include	"mlx.h"
#include	"util_action.h"
#include	<math.h>
#include	"cub3d.h"

static double	get_ratio(t_cub3d_info *info, t_ray_info *ray_info);

int	ray_loop(t_cub3d_info *info)
{
	mlx_clear_window(info->mlx, info->window);
	if (info->mouse == FALSE)
		get_mouse_action(info);
	ray_cast(info);
	return (0);
}

void	calc_wall_height(t_cub3d_info *info, t_ray_info *ray_info)
{
	if (ray_info->is_side == FALSE)
		ray_info->wall_dist = (ray_info->ray.x - info->player.pos.x + \
					(1 - ray_info->ray_move_dir.x) / 2) / ray_info->raydir.x;
	else
		ray_info->wall_dist = (ray_info->ray.y - info->player.pos.y + \
					(1 - ray_info->ray_move_dir.y) / 2) / ray_info->raydir.y;
	ray_info->wall_height = (int)(SCREEN_HEIGHT / ray_info->wall_dist);
	ray_info->draw_start = -ray_info->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (ray_info->draw_start < 0)
		ray_info->draw_start = 0;
	ray_info->draw_end = ray_info->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (SCREEN_HEIGHT <= ray_info->draw_end)
		ray_info->draw_end = SCREEN_HEIGHT - 1;
}

void	ver_line_each_side(t_cub3d_info *info, t_ray_info *ray_info, \
												t_vector *screen)
{
	if (is_wall_east_side(ray_info) == TRUE)
		ver_line(info, ray_info, screen, &info->textures.wall_ea);
	else if (is_wall_west_side(ray_info) == TRUE)
		ver_line(info, ray_info, screen, &info->textures.wall_we);
	else if (is_wall_north_side(ray_info) == TRUE)
		ver_line(info, ray_info, screen, &info->textures.wall_no);
	else if (is_wall_south_side(ray_info) == TRUE)
		ver_line(info, ray_info, screen, &info->textures.wall_so);
}

void	ver_line(t_cub3d_info *info, t_ray_info *ray_info, \
											t_vector *screen, t_img *texture)
{
	char		*dest_addr;
	char		*src_addr;
	t_vector	img;
	double		ratio;
	int			x;

	x = SCREEN_WIDTH - 1 - screen->x;
	ratio = get_ratio(info, ray_info);
	img.x = (int)(ratio * texture->width);
	screen->y = ray_info->draw_start;
	while (screen->y < ray_info->draw_end)
	{
		if (ray_info->wall_height > SCREEN_HEIGHT)
			img.y = ((double)texture->height) / ray_info->wall_height \
					* ((ray_info->wall_height - SCREEN_HEIGHT) / 2 + screen->y);
		else
			img.y = (int)((screen->y - ray_info->draw_start) \
							/ ray_info->wall_height * texture->height);
		dest_addr = get_pixel_addr_img(&info->textures.background, x, \
															screen->y);
		src_addr = get_pixel_addr_img(texture, img.x, img.y);
		*(unsigned int *)dest_addr = *(unsigned int *)src_addr;
		screen->y++;
	}
}

static double	get_ratio(t_cub3d_info *info, t_ray_info *ray_info)
{
	double		ratio;

	if (ray_info->is_side == TRUE)
	{
		ratio = info->player.pos.x + ray_info->wall_dist * ray_info->raydir.x;
		ratio -= floor(ratio);
		ray_info->ray.x += ratio;
	}
	else
	{
		ratio = info->player.pos.y + ray_info->wall_dist * ray_info->raydir.y;
		ratio -= floor(ratio);
		ray_info->ray.y += ratio;
	}
	if (is_wall_north_side(ray_info) == TRUE || is_wall_east_side(ray_info))
		ratio = 1 - ratio;
	return (ratio);
}
