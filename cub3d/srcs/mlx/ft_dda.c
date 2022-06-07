/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:16:37 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:09:35 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_delta(t_data *data, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	data->ray_x = data->dir_x + data->field_x * cam_x;
	data->ray_y = data->dir_y + data->field_y * cam_x;
	if (data->ray_x == 0)
		data->delta_y = 0;
	else if (data->ray_x == 1)
		data->delta_y = 1;
	else
		data->delta_y = fabs(1 / data->ray_y);
	if (data->ray_y == 0)
		data->delta_x = 0;
	else if (data->ray_y == 1)
		data->delta_x = 1;
	else
		data->delta_x = fabs(1 / data->ray_x);
}

void	init_dda(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->side_x = (data->px - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->side_x = (data->map_x + 1.0 - data->px) * data->delta_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->side_y = (data->py - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->side_y = (data->map_y + 1.0 - data->py) * data->delta_y;
	}
}

void	execute_dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (data->side_x < data->side_y)
		{
			data->side_x += data->delta_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_y += data->delta_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			hit = 1;
	}
}

void	ft_dda(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		data->map_x = (int)data->px;
		data->map_y = (int)data->py;
		get_delta(data, x);
		init_dda(data);
		execute_dda(data);
		if (data->side == 0)
			data->distance = (data->map_x - data->px
					+ (1 - data->step_x) / 2) / data->ray_x;
		else
			data->distance = (data->map_y - data->py
					+ (1 - data->step_y) / 2) / data->ray_y;
		drawing(data, x);
		x++;
	}
}
