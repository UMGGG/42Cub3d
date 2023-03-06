/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/01/30 18:00:48 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"mlx.h"
#include	"util_error.h"
#include	<stdlib.h>

void	init_mlx_win(t_cub3d_info *info)
{
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		exit_with_error("mlx init error");
	info->window = mlx_new_window(info->mlx, \
								SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (info->window == NULL)
		exit_with_error("window init error");
}

void	destroy_window(t_cub3d_info *info)
{
	if (info->window)
		mlx_destroy_window(info->mlx, info->window);
}
