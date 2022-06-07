/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:06:20 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:09:42 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_data *data, int x, int y)
{
	unsigned int	*dst;

	if (data->side && data->ray_y > 0)
		dst = (unsigned int *)(data->south.addr
				+ (y * data->south.size_line
					+ x * (data->south.bits_per_pixel / 8)));
	else if (data->side && data->ray_y <= 0)
		dst = (unsigned int *)(data->north.addr
				+ (y * data->north.size_line
					+ x * (data->north.bits_per_pixel / 8)));
	else if (!data->side && data->ray_x > 0)
		dst = (unsigned int *)(data->east.addr
				+ (y * data->east.size_line
					+ x * (data->east.bits_per_pixel / 8)));
	else
		dst = (unsigned int *)(data->west.addr
				+ (y * data->west.size_line
					+ x * (data->west.bits_per_pixel / 8)));
	return (*dst);
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
