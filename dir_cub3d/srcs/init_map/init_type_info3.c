/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type_info3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:20:47 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 16:21:52 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"
#include	"libft.h"
#include	"util_safe_libft.h"
#include	"util_init_map.h"
#include	"util_error.h"

char	*get_info_line(char *line, int start_num)
{
	int		start;
	char	*info_line;

	start = start_num;
	if (line[start] && line[start] != ' ')
		exit_with_error("space not found at identifier");
	while (line[start] && line[start] == ' ')
	{
		start++;
	}
	info_line = safe_ft_substr(line, start, ft_strlen(line) - start);
	return (info_line);
}
