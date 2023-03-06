/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:33:01 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/07 16:21:28 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_INIT_H
# define UTIL_INIT_H

void	init_mlx_win(t_cub3d_info *info);
void	init_imgs(t_cub3d_info *info);
void	init_background_img(t_img *background, \
						unsigned int ceiling_color, unsigned int floor_color);
char	*get_info_line(char *line, int start_num);

#endif
