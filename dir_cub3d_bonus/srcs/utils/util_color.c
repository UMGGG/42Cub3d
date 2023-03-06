/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:35:14 by jiwolee           #+#    #+#             */
/*   Updated: 2023/01/12 21:30:01 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_color.h"

unsigned int	make_color(int a, int r, int g, int b)
{
	unsigned int	color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}
