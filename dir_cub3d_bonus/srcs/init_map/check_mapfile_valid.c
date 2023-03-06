/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:39:55 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/08 17:37:43 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_error.h"
#include	"util_init_map.h"

static int	classify_moveable_space(char map_data);
static void	check_position_moveable_space(t_map *map, unsigned int x, \
														unsigned int y);
static void	check_position(t_map *map, unsigned int x, unsigned int y);
static void	init_player(t_cub3d_info *info, unsigned int x, unsigned int y);

int	check_valid_map(t_cub3d_info *info)
{
	unsigned int		x;
	unsigned int		y;
	int					start_point;

	x = 0;
	y = 0;
	start_point = 0;
	while (y < info->map.height)
	{
		while (x < info->map.width)
		{
			check_position(&info->map, x, y);
			if (classify_moveable_space(info->map.data[y][x]) == 2)
			{
				start_point++;
				init_player(info, x, y);
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (start_point != 1)
		exit_with_error("start_points error");
	return (TRUE);
}

static void	check_position(t_map *map, unsigned int x, unsigned int y)
{
	if (is_valid_char(map->data[y][x]) == FALSE)
		exit_with_error("invalid char in map");
	if (classify_moveable_space(map->data[y][x]))
		check_position_moveable_space(map, x, y);
}

static void	check_position_moveable_space(t_map *map, unsigned int x, \
														unsigned int y)
{
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
		exit_with_error("map isn't closed");
	else if (map->data[y - 1][x - 1] == ' ' || map->data[y - 1][x] == ' ' || \
		map->data[y - 1][x + 1] == ' ' || map->data[y][x - 1] == ' ' || \
		map->data[y][x + 1] == ' ' || map->data[y + 1][x - 1] == ' ' || \
		map->data[y + 1][x] == ' ' || map->data[y + 1][x + 1] == ' ')
		exit_with_error("map isn't closed");
}

static int	classify_moveable_space(char map_data)
{
	if (map_data == 'N' || map_data == 'S' \
			|| map_data == 'E' || map_data == 'W')
		return (2);
	else if (map_data == '0' || map_data == '2' || map_data == '3')
		return (1);
	return (0);
}

static void	init_player(t_cub3d_info *info, unsigned int x, unsigned int y)
{
	double	plane_size;

	plane_size = 0.66;
	info->player.pos.x = (double)x + 0.5;
	info->player.pos.y = (double)y + 0.5;
	if (info->map.data[y][x] == 'N')
	{
		set_vector_xy(&(info->player.dir), (double)0, (double)-1);
		set_vector_xy(&(info->player.plane), -plane_size, (double)0.0);
	}
	else if (info->map.data[y][x] == 'S')
	{
		set_vector_xy(&(info->player.dir), (double)0, (double)1);
		set_vector_xy(&(info->player.plane), plane_size, (double)0.0);
	}
	else if (info->map.data[y][x] == 'W')
	{
		set_vector_xy(&(info->player.dir), (double)-1, (double)0);
		set_vector_xy(&(info->player.plane), (double)0.0, plane_size);
	}
	else if (info->map.data[y][x] == 'E')
	{
		set_vector_xy(&(info->player.dir), (double)1, (double)0);
		set_vector_xy(&(info->player.plane), (double)0.0, -plane_size);
	}
}
