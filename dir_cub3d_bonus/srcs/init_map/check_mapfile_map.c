/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:22:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/08 17:37:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"util_init_map.h"
#include	"get_next_line.h"
#include	"util_error.h"
#include	<stdio.h>

static unsigned int	check_map_width(char *line);
static char			*skip_empty_line(int fd);

void	check_mapfile_map(int fd, t_cub3d_info *info)
{
	t_map			*map;
	unsigned int	height;
	unsigned int	width;
	char			*line;

	map = &info->map;
	map->width = 0;
	height = 0;
	width = 0;
	line = skip_empty_line(fd);
	if (!line)
		exit_with_error("no map data");
	while (line)
	{
		width = check_map_width(line);
		if (width > map->width)
			map->width = width;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
}

static char	*skip_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && line[0] == '\0')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static unsigned int	check_map_width(char *line)
{
	unsigned int	width;

	width = 0;
	if (line[0] == '\n')
		exit_with_error("\n while map");
	while (line[width])
		width++;
	return (width);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == '3' || \
	c == 'E' || c == 'W' || c == ' ' || c == '2' || c == '\n')
		return (TRUE);
	return (FALSE);
}
