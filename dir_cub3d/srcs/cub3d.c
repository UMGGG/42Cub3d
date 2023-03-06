/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:58:05 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/07 17:35:04 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_img.h"
#include	<../mlx/mlx.h>
#include	"libft.h"
#include	"util_init_map.h"
#include	"cub3d.h"
#include	"util_init.h"
#include	"ray_cast.h"
#include	"util_action.h"
#include	"util_error.h"
#include	"minimap.h"

void	memset_info(t_cub3d_info *info);

int	main(int argc, char *argv[])
{
	t_cub3d_info	info;

	memset_info(&info);
	info.mouse = TRUE;
	if (argc == 2)
	{
		init_map(&info, argv[1]);
		check_valid_map(&info);
		init_mlx_win(&info);
		init_imgs(&info);
		init_minimap_img(&info, &info.map);
	}
	else
		exit_with_error("argc error");
	mlx_hook(info.window, 2, 0, &key_pressed, &info);
	mlx_hook(info.window, KEY_EXIT, 0, &exit_pressed, &info);
	mlx_loop_hook(info.mlx, &ray_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}

void	memset_info(t_cub3d_info *info)
{
	ft_bzero(info, sizeof(t_cub3d_info));
}
