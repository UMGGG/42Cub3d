/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:12:25 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/07 17:31:37 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_INIT_MAP_H
# define UTIL_INIT_MAP_H

# include "cub3d.h"

t_cub3d_info	*init_map(t_cub3d_info *info, char *map_file_name);

char			*get_info_line(char *line, int start_num);

void			check_mapfile_map(int fd, t_cub3d_info *info);

void			check_mapfile_info(int fd, t_cub3d_info *info);
int				check_line(char *line, t_cub3d_info *info);
int				is_type_identifier(char *line, char *type);
int				is_empty_line(char *line);
int				is_valid_char(char c);

void			init_type_info_no(t_textures_info *textures_fname, char *line);
void			init_type_info_so(t_textures_info *textures_fname, char *line);
void			init_type_info_ea(t_textures_info *textures_fname, char *line);
void			init_type_info_we(t_textures_info *textures_fname, char *line);

void			init_type_info_f(t_textures_info *textures_info, char *line);
void			init_type_info_c(t_textures_info *textures_info, char *line);

void			read_save_map(int fd, t_map *map);

int				check_valid_map(t_cub3d_info *info);
void			set_vector_xy(t_vector *vec, double x, double y);

#endif
