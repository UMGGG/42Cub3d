/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:17 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/09 17:04:01 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_init_map.h"
#include	"cub3d.h"
#include	"get_next_line.h"
#include	"util_error.h"
#include	"util_safe_libft.h"
#include	"libft.h"
#include	<fcntl.h>

static int	is_valid_mapfile_name(char *mapname);
int			safe_open(char *file_name);

t_cub3d_info	*init_map(t_cub3d_info *info, char *map_file_name)
{
	int	fd;

	if (info)
	{
		if (is_valid_mapfile_name(map_file_name) == FALSE)
			exit_with_error("invalid map file error");
		fd = safe_open(map_file_name);
		check_mapfile_info(fd, info);
		check_mapfile_map(fd, info);
		close(fd);
		fd = safe_open(map_file_name);
		read_save_map(fd, &info->map);
		close(fd);
	}
	return (info);
}

int	safe_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_with_error("file open failed error");
	return (fd);
}

static int	is_valid_mapfile_name(char *mapname)
{
	char	*addr;

	if (mapname)
	{
		addr = ft_strrchr(mapname, '.');
		if (addr && ft_strncmp(addr, ".cub\0", 5) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	set_vector_xy(t_vector *vec, double x, double y)
{
	if (vec == NULL)
		exit_with_error("vector is NULL");
	vec->x = x;
	vec->y = y;
}
