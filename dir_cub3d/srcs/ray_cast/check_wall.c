/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:18:13 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/06 00:17:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"ray_cast.h"

int	is_wall_south_side(t_ray_info *ray_info)
{
	if (ray_info->is_side == TRUE && ray_info->ray_move_dir.y < 0)
		return (TRUE);
	return (FALSE);
}

int	is_wall_north_side(t_ray_info *ray_info)
{
	if (ray_info->is_side == TRUE && ray_info->ray_move_dir.y > 0)
		return (TRUE);
	return (FALSE);
}

int	is_wall_east_side(t_ray_info *ray_info)
{
	if (ray_info->is_side == FALSE && ray_info->ray_move_dir.x < 0)
		return (TRUE);
	return (FALSE);
}

int	is_wall_west_side(t_ray_info *ray_info)
{
	if (ray_info->is_side == FALSE && ray_info->ray_move_dir.x > 0)
		return (TRUE);
	return (FALSE);
}
