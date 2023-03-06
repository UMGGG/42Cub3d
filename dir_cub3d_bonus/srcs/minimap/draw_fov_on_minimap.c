/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov_on_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:16:57 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/07 17:10:37 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minimap.h"
#include	"cub3d.h"
#include	"ray_cast.h"

static void	init_b_info(t_bresenham_info *b_info, t_cub3d_info *cub_info, \
														t_ray_info *ray_info);
static void	draw_line_base_x(t_bresenham_info *b_info, t_cub3d_info *cub_info);
static void	draw_line_base_y(t_bresenham_info *b_info, t_cub3d_info *cub_info);
static void	init_b_info2(t_bresenham_info *b_info);

void	draw_fov_on_minimap(t_cub3d_info *cub_info, t_ray_info *ray_info)
{
	t_bresenham_info	b_info;

	if (cub_info && ray_info)
	{
		init_b_info(&b_info, cub_info, ray_info);
		b_info.dy <<= 1;
		b_info.dx <<= 1;
		if (b_info.dx > b_info.dy)
			draw_line_base_x(&b_info, cub_info);
		else
			draw_line_base_y(&b_info, cub_info);
	}
}

static void	draw_line_base_x(t_bresenham_info *b_info, t_cub3d_info *cub_info)
{
	char	*addr;

	b_info->fraction = b_info->dy - (b_info->dx >> 1);
	while (b_info->start_x != b_info->end_x)
	{
		if (b_info->fraction >= 0)
		{
			b_info->start_y += b_info->stepy;
			b_info->fraction -= b_info->dx;
		}
		b_info->start_x += b_info->stepx;
		b_info->fraction += b_info->dy;
		addr = get_pixel_addr_img(&cub_info->textures.minimap, \
											b_info->start_x, b_info->start_y);
		if (addr)
			*(unsigned *)addr = 0X00FFFFFF;
		else
			break ;
	}
}

static void	draw_line_base_y(t_bresenham_info *b_info, t_cub3d_info *cub_info)
{
	char	*addr;

	b_info->fraction = b_info->dx - (b_info->dy >> 1);
	while (b_info->start_y != b_info->end_y)
	{
		if (b_info->fraction >= 0)
		{
			b_info->start_x += b_info->stepx;
			b_info->fraction -= b_info->dy;
		}
		b_info->start_y += b_info->stepy;
		b_info->fraction += b_info->dx;
		addr = get_pixel_addr_img(&cub_info->textures.minimap, \
											b_info->start_x, b_info->start_y);
		if (addr)
			*(unsigned *)addr = 0XFFFFFF;
		else
			break ;
	}
}

static void	init_b_info(t_bresenham_info *b_info, t_cub3d_info *cub_info, \
														t_ray_info *ray_info)
{
	int	fullmini_x;
	int	fullmini_y;
	int	block_size;

	block_size = cub_info->minimap_info.block_size;
	fullmini_x = cub_info->player.pos.x * 10 \
									- (cub_info->textures.minimap.width / 2);
	fullmini_y = cub_info->player.pos.y * 10 \
									- (cub_info->textures.minimap.height / 2);
	b_info->start_x = (int)(cub_info->player.pos.x * 10.0) - fullmini_x;
	b_info->start_y = (int)(cub_info->player.pos.y * 10.0) - fullmini_y;
	ray_info->ray.y -= 1;
	ray_info->ray.x -= 1;
	if (is_wall_east_side(ray_info))
		ray_info->ray.x += 1;
	else if (is_wall_south_side(ray_info))
		ray_info->ray.y += 1;
	b_info->end_x = (int)(ray_info->ray.x * 10.0) + block_size - fullmini_x;
	b_info->end_y = (int)(ray_info->ray.y * 10.0) + block_size - fullmini_y;
	init_b_info2(b_info);
}

static void	init_b_info2(t_bresenham_info *b_info)
{
	b_info->dx = b_info->end_x - b_info->start_x;
	b_info->dy = b_info->end_y - b_info->start_y;
	b_info->stepx = 1;
	b_info->stepy = 1;
	if (b_info->dy < 0)
	{
		b_info->dy = -b_info->dy;
		b_info->stepy = -1;
	}
	if (b_info->dx < 0)
	{
		b_info->dx = -b_info->dx;
		b_info->stepx = -1;
	}
	b_info->dy <<= 1;
	b_info->dx <<= 1;
}
