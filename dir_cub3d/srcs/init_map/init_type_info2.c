/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type_info2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:57:44 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 17:32:43 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"libft.h"
#include	"util_safe_libft.h"
#include	"util_init_map.h"
#include	"util_error.h"

void	init_type_info_no(t_textures_info *textures_info, char *line)
{
	char	*info_line;

	if (textures_info->wall_no_file_name == NULL)
	{
		info_line = get_info_line(line, 2);
		textures_info->wall_no_file_name = info_line;
	}
	else
		exit_with_error("identifier error NO");
}

void	init_type_info_so(t_textures_info *textures_info, char *line)
{
	char	*info_line;

	if (textures_info->wall_so_file_name == NULL)
	{
		info_line = get_info_line(line, 2);
		textures_info->wall_so_file_name = info_line;
	}
	else
		exit_with_error("identifier error SO");
}

void	init_type_info_ea(t_textures_info *textures_info, char *line)
{
	char	*info_line;

	if (textures_info->wall_ea_file_name == NULL)
	{
		info_line = get_info_line(line, 2);
		textures_info->wall_ea_file_name = info_line;
	}
	else
		exit_with_error("identifier error EA");
}

void	init_type_info_we(t_textures_info *textures_info, char *line)
{
	char	*info_line;

	if (textures_info->wall_we_file_name == NULL)
	{
		info_line = get_info_line(line, 2);
		textures_info->wall_we_file_name = info_line;
	}
	else
		exit_with_error("identifier error WE");
}
