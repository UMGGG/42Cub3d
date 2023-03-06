/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:36:51 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/06 15:31:00 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_ACTION_H
# define UTIL_ACTION_H

# include "cub3d.h"

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_SPACE		49
# define KEY_ESC		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define MOUSE_ON_OFF	20
# define KEY_EXIT		17

int		key_pressed(int key, t_cub3d_info *info);
void	move_player(t_cub3d_info *info, double speed);
void	move_player_side(t_cub3d_info *info, double speed);
void	rotate_player(t_cub3d_info *info, double speed);
void	mouse_cursor_on_off(t_cub3d_info *info);
void	get_mouse_action(t_cub3d_info *info);
int		key_pressed_space(int key, t_cub3d_info *info);
int		exit_pressed(int key);

#endif
