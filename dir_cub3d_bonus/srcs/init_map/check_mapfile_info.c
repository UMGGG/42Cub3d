/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:21 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/01/30 16:47:37 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"
#include	"cub3d.h"
#include	"util_init_map.h"
#include	"get_next_line.h"
#include	"util_error.h"

int			is_type_identifier(char *line, char *type);
static int	is_all_info(int save_info_cnt);

void	check_mapfile_info(int fd, t_cub3d_info *info)
{
	char	*line;
	int		save_info_cnt;

	save_info_cnt = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_line(line) == TRUE)
			;
		else
		{
			if (check_line(line, info))
				save_info_cnt++;
			if (is_all_info(save_info_cnt) == TRUE)
			{
				free(line);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	exit_with_error("can't find identifier");
}

int	check_line(char *line, t_cub3d_info *info)
{
	t_textures_info	*textures_fname;

	textures_fname = &info->textures_info;
	if (is_type_identifier(line, "NO"))
		init_type_info_no(textures_fname, line);
	else if (is_type_identifier(line, "EA"))
		init_type_info_ea(textures_fname, line);
	else if (is_type_identifier(line, "WE"))
		init_type_info_we(textures_fname, line);
	else if (is_type_identifier(line, "SO"))
		init_type_info_so(textures_fname, line);
	else if (is_type_identifier(line, "DO"))
		init_type_info_do(textures_fname, line);
	else if (is_type_identifier(line, "C"))
		init_type_info_c(textures_fname, line);
	else if (is_type_identifier(line, "F"))
		init_type_info_f(textures_fname, line);
	else
		exit_with_error("identifier error");
	return (1);
}

int	is_type_identifier(char *line, char *type)
{
	if (ft_strncmp(line, type, ft_strlen(type)) == 0)
		return (TRUE);
	return (FALSE);
}

int	is_empty_line(char *line)
{
	int	idx;

	idx = 0;
	if (line)
	{
		while ((line[idx] >= 9 && line[idx] <= 13) || line[idx] == ' ')
			idx++;
		if ((int)ft_strlen(line) == idx)
			return (TRUE);
	}
	return (FALSE);
}

static int	is_all_info(int save_info_cnt)
{
	if (save_info_cnt == 7)
		return (TRUE);
	return (FALSE);
}
