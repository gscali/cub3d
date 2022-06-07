/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:44:35 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:09:59 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	xpm_to_img1(t_data *data)
{
	int	size;

	size = 10;
	data->txt[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/cursor.xpm", &size, &size);
	data->txt[0].addr = mlx_get_data_addr(data->txt[0].img,
			&data->txt[0].bits_per_pixel,
			&data->txt[0].size_line,
			&data->txt[0].endian);
	data->txt[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/mini_wall.xpm", &size, &size);
	data->txt[1].addr = mlx_get_data_addr(data->txt[1].img,
			&data->txt[1].bits_per_pixel,
			&data->txt[1].size_line,
			&data->txt[1].endian);
	data->txt[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/mini_empty.xpm", &size, &size);
	data->txt[2].addr = mlx_get_data_addr(data->txt[2].img,
			&data->txt[2].bits_per_pixel,
			&data->txt[2].size_line,
			&data->txt[2].endian);
}

void	xpm_to_img2(t_data *data)
{
	int	size;

	size = 2048;
	data->north.img = mlx_xpm_file_to_image(data->mlx_ptr, data->no,
			&size, &size);
	data->north.addr = mlx_get_data_addr(data->north.img,
			&data->north.bits_per_pixel,
			&data->north.size_line, &data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx_ptr, data->so,
			&size, &size);
	data->south.addr = mlx_get_data_addr(data->south.img,
			&data->south.bits_per_pixel,
			&data->south.size_line, &data->south.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx_ptr, data->we,
			&size, &size);
	data->west.addr = mlx_get_data_addr(data->west.img,
			&data->west.bits_per_pixel,
			&data->west.size_line, &data->west.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea,
			&size, &size);
	data->east.addr = mlx_get_data_addr(data->east.img,
			&data->east.bits_per_pixel,
			&data->east.size_line, &data->east.endian);
}

void	xpm_to_img(t_data *data)
{
	xpm_to_img1(data);
	xpm_to_img2(data);
}
