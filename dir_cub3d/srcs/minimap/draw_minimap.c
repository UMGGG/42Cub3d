/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:00:16 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/06 16:04:10 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_img.h"
#include	"minimap.h"
#include	"mlx.h"
#include	<stdlib.h>

static void	init_minimap_data(t_cub3d_info *info, \
									t_vector *mini_pos, t_vector *mini_size);
static void	draw_minimap_map(t_cub3d_info *info, \
									t_vector *mini_pos, t_vector *mini_size);
static void	draw_minimap_player(t_cub3d_info *info, t_vector *mini_player_pos);

void	draw_minimap(t_cub3d_info *info)
{
	t_vector	mini_pos;
	t_vector	mini_size;

	init_minimap_data(info, &mini_pos, &mini_size);
	draw_minimap_map(info, &mini_pos, &mini_size);
	draw_minimap_player(info, &mini_size);
}

static void	init_minimap_data(t_cub3d_info *info, \
									t_vector *mini_pos, t_vector *mini_size)
{
	int	block_size;

	block_size = info->minimap_info.block_size;
	mini_size->x = SCREEN_WIDTH / 10;
	mini_size->y = SCREEN_HEIGHT / 10;
	mini_pos->x = (info->player.pos.x * block_size) - mini_size->x / 2;
	mini_pos->y = (info->player.pos.y * block_size) - mini_size->y / 2;
}

static void	draw_minimap_map(t_cub3d_info *info, \
									t_vector *mini_pos, t_vector *mini_size)
{
	char	*mini_addr;
	char	*fullmini_addr;
	int		x;
	int		y;

	y = 0;
	while (y < mini_size->y)
	{
		x = 0;
		while (x < mini_size->x)
		{
			mini_addr = get_pixel_addr_img(&info->textures.minimap, x, y);
			fullmini_addr = get_pixel_addr_img(&info->textures.full_minimap, \
									mini_pos->x + x, mini_pos->y + y);
			if (mini_addr && fullmini_addr == NULL)
				*(unsigned int *)mini_addr = info->minimap_info.empty_color;
			else if (mini_addr)
				*(unsigned int *)mini_addr = *(unsigned int *)fullmini_addr;
			++x;
		}
		++y;
	}
}

static void	draw_minimap_player(t_cub3d_info *info, t_vector *mini_size)
{
	int				x;
	int				y;
	unsigned int	color;
	int				player_block_size;
	char			*minimap_addr;

	player_block_size = 3;
	color = info->minimap_info.player_color;
	y = 0;
	while (y < player_block_size)
	{
		x = 0;
		while (x < player_block_size)
		{
			minimap_addr = get_pixel_addr_img(&info->textures.minimap, \
									mini_size->x / 2 + x, mini_size->y / 2 + y);
			if (minimap_addr)
				*(unsigned int *)minimap_addr = color;
			++x;
		}
		++y;
	}
}
