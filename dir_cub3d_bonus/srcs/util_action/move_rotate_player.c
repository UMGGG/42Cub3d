/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:12:59 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/03 15:36:59 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_action.h"
#include	<math.h>

static int		classify_moveable_space(char map_data);
static t_vector	rotate_vector(t_vector vector, double rot_speed);

void	move_player(t_cub3d_info *info, double speed)
{
	double	new_x;
	double	new_y;

	new_x = info->player.dir.x * speed * 2 + info->player.pos.x;
	new_y = info->player.dir.y * speed * 2 + info->player.pos.y;
	if (classify_moveable_space(info->map.data[(int)new_y][(int)new_x]))
	{
		info->player.pos.x = info->player.dir.x * speed + info->player.pos.x;
		info->player.pos.y = info->player.dir.y * speed + info->player.pos.y;
	}
}

void	move_player_side(t_cub3d_info *info, double speed)
{
	double		new_x;
	double		new_y;
	t_vector	side_dir;
	double		radian;
	double		degree;

	degree = 90;
	radian = degree * 3.141592f / 180;
	side_dir.x = info->player.dir.x;
	side_dir.y = info->player.dir.y;
	side_dir = rotate_vector(side_dir, radian);
	new_x = side_dir.x * speed * 2 + info->player.pos.x;
	new_y = side_dir.y * speed * 2 + info->player.pos.y;
	if (classify_moveable_space(info->map.data[(int)new_y][(int)new_x]))
	{
		info->player.pos.x = side_dir.x * speed + info->player.pos.x;
		info->player.pos.y = side_dir.y * speed + info->player.pos.y;
	}
}

void	rotate_player(t_cub3d_info *info, double speed)
{
	t_player	*player;
	double		new_x;
	double		new_y;

	player = &(info->player);
	{
		new_x = player->dir.x * cos(speed) - player->dir.y * sin(speed);
		new_y = player->dir.x * sin(speed) + player->dir.y * cos(speed);
		player->dir.x = new_x;
		player->dir.y = new_y;
	}
	{
		new_x = player->plane.x * cos(speed) - player->plane.y * sin(speed);
		new_y = player->plane.x * sin(speed) + player->plane.y * cos(speed);
		player->plane.x = new_x;
		player->plane.y = new_y;
	}
}

static t_vector	rotate_vector(t_vector vector, double rot_speed)
{
	double		new_x;
	double		new_y;

	new_x = vector.x * cos(rot_speed) - vector.y * sin(rot_speed);
	new_y = vector.x * sin(rot_speed) + vector.y * cos(rot_speed);
	vector.x = new_x;
	vector.y = new_y;
	return (vector);
}

static int	classify_moveable_space(char map_data)
{
	if (map_data == '1' || map_data == '2')
		return (0);
	return (1);
}
