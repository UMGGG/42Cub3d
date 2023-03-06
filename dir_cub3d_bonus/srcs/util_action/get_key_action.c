/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:11 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/07 16:23:06 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_action.h"
#include	<stdlib.h>

int	key_pressed(int key, t_cub3d_info *info)
{
	if (key == KEY_W)
		move_player(info, MOVE_SPEED);
	else if (key == KEY_A)
		move_player_side(info, -MOVE_SPEED);
	else if (key == KEY_S)
		move_player(info, -MOVE_SPEED);
	else if (key == KEY_D)
		move_player_side(info, MOVE_SPEED);
	else if (key == KEY_LEFT)
		rotate_player(info, -ROTATE_SPEED);
	else if (key == KEY_RIGHT)
		rotate_player(info, ROTATE_SPEED);
	else if (key == MOUSE_ON_OFF)
		mouse_cursor_on_off(info);
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	exit_pressed(int key)
{
	(void)key;
	exit (0);
}
