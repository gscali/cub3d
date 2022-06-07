/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:06:47 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:09:21 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->start)
	{
		ft_put_pixel(data, x, y, data->ceiling_rgb);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;

	y = data->end;
	while (y < HEIGHT)
	{
		ft_put_pixel(data, x, y, data->floor_rgb);
		y++;
	}
}

void	draw_wall(t_data *data, int line_h, int x)
{
	int				y;
	double			step;
	double			txt_pos;
	int				txt_x;
	int				txt_y;

	if (data->side == 0)
		data->wall_pos = data->py + data->distance * data->ray_y;
	else
		data->wall_pos = data->px + data->distance * data->ray_x;
	data->wall_pos -= floor(data->wall_pos);
	txt_x = (int)(data->wall_pos * SIZE);
	step = 1.0 * SIZE / line_h;
	txt_pos = (data->start - HEIGHT / 2 + line_h / 2) * step;
	y = data->start;
	while (y < data->end)
	{
		txt_y = (int)txt_pos & (SIZE - 1);
		txt_pos += step;
		data->color = get_color(data, txt_x, txt_y);
		ft_put_pixel(data, x, y, data->color);
		y++;
	}
}

void	drawing(t_data *data, int x)
{
	int		line_h;
	double	ratio;

	ratio = ((double)WIDTH / (double)HEIGHT) / (4.0 / 3.0);
	line_h = ((double)HEIGHT * ratio) / (data->distance);
	data->start = CENTER - line_h / 2;
	if (data->start < 0)
		data->start = 0;
	data->end = line_h / 2 + CENTER;
	if (data->end > HEIGHT || data->end < 0)
		data->end = HEIGHT - 1;
	draw_ceiling(data, x);
	draw_wall(data, line_h, x);
	draw_floor(data, x);
}
