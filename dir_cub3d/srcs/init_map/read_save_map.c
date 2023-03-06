/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_save_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:00:21 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 17:32:53 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_init_map.h"
#include	"cub3d.h"
#include	"util_safe_libft.h"
#include	"get_next_line.h"
#include	"libft.h"

static char	*skip_mapfile_info_line(int fd);
static int	is_info_line(char *line);
static char	*make_line_width(char *line, int width);
static char	*fill_line_back_to_blank(char *line, char *new_line, int width);

void	read_save_map(int fd, t_map *map)
{
	char			*line;
	unsigned int	y;

	map->data = (char **)safe_ft_calloc(map->height, sizeof(char *));
	line = skip_mapfile_info_line(fd);
	y = 0;
	while (line && y < map->height)
	{
		map->data[y] = make_line_width(line, map->width);
		free(line);
		line = get_next_line(fd);
		y++;
	}
}
//	map->data = ft_calloc(map->height, sizeof(char *)); // safe_ft_calloc

static char	*skip_mapfile_info_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_info_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	is_info_line(char *line)
{
	if (is_type_identifier(line, "NO") || is_type_identifier(line, "EA") \
		|| is_type_identifier(line, "WE") || is_type_identifier(line, "SO") \
		|| is_type_identifier(line, "C") || is_type_identifier(line, "F") \
		|| is_empty_line(line))
		return (TRUE);
	return (FALSE);
}

static char	*make_line_width(char *line, int width)
{
	char	*new_line;

	new_line = safe_ft_calloc(width + 1, sizeof(char));
	new_line = ft_memcpy(new_line, line, ft_strlen(line));
	new_line = fill_line_back_to_blank(line, new_line, width);
	return (new_line);
}

static char	*fill_line_back_to_blank(char *line, char *new_line, int width)
{
	int	idx;

	idx = 0;
	idx = ft_strlen(line);
	if (new_line[idx] == '\n')
		--idx;
	while (idx < width)
	{
		new_line[idx] = ' ';
		++idx;
	}
	new_line[idx] = '\0';
	return (new_line);
}
