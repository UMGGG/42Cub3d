/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:29:40 by jiwolee           #+#    #+#             */
/*   Updated: 2023/02/06 16:06:27 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_img.h"
#include	"util_safe_libft.h"
#include	<mlx.h>
#include	<stdlib.h>

static t_img	*file_to_img(t_img *img, char *file_name, void *mlx_ptr);
static t_img	*get_data_img_addr(t_img *img);

t_img	*load_img(char *file_name, void *mlx_ptr)
{
	t_img	*new_img;

	if (file_name && mlx_ptr)
	{
		new_img = (t_img *)safe_ft_calloc(1, sizeof(t_img));
		new_img = file_to_img(new_img, file_name, mlx_ptr);
		new_img = get_data_img_addr(new_img);
		if (new_img && new_img->img_ptr && new_img->addr)
			return (new_img);
		free (new_img);
	}
	return (NULL);
}

t_img	*delete_img(t_img *img, void *mlx_ptr)
{
	if (img && img->img_ptr)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
	if (img)
		free (img);
	return (NULL);
}

char	*get_pixel_addr_img(t_img *img, int x, int y)
{
	unsigned long long	color_addr;
	unsigned long long	x_addr;
	unsigned long long	y_addr;

	if (img && img->addr && 0 <= x && x < img->width \
							&& 0 <= y && y < img->height)
	{
		y_addr = y * img->line_length;
		x_addr = x * img->bits_per_pixel / 8;
		color_addr = (unsigned long long)img->addr + y_addr + x_addr;
		return ((char *)color_addr);
	}
	return (NULL);
}

static t_img	*file_to_img(t_img *img, char *file_name, void *mlx_ptr)
{
	if (img && file_name && mlx_ptr)
	{
		img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_name, \
									&img->width, &img->height);
		if (img->img_ptr)
			return (img);
	}
	return (NULL);
}

static t_img	*get_data_img_addr(t_img *img)
{
	if (img && img->img_ptr)
	{
		img->addr = mlx_get_data_addr(img->img_ptr, \
				&img->bits_per_pixel, &img->line_length, &img->endian);
		if (img->addr)
			return (img);
	}
	return (NULL);
}
