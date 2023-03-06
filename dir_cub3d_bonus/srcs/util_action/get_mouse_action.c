/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:34:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/01/31 17:43:27 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"mlx.h"
#include	"util_action.h"

void	get_mouse_action(t_cub3d_info *info)
{
	int	new_x;
	int	new_y;

	mlx_mouse_get_pos(info->window, &new_x, &new_y);
	if (new_x > SCREEN_WIDTH / 2)
		rotate_player(info, MOUSE_ROTATE_SPEED);
	else if (new_x < SCREEN_WIDTH / 2)
		rotate_player(info, -MOUSE_ROTATE_SPEED);
	mlx_mouse_move(info->window, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void	mouse_cursor_on_off(t_cub3d_info *info)
{
	if (info->mouse == TRUE)
	{
		mlx_mouse_hide();
		mlx_mouse_move(info->window, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		info->mouse = FALSE;
	}
	else
	{
		mlx_mouse_show();
		info->mouse = TRUE;
	}
}
