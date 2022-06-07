/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:57:16 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:09:28 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(floor(data->py + data->dir_y * MOVESPEED))]
	[(int)(floor(data->px))] == '0')
		data->py += data->dir_y * MOVESPEED;
	if (data->map[(int)(floor(data->py))]
	[(int)(floor(data->px + data->dir_x * MOVESPEED))] == '0')
		data->px += data->dir_x * MOVESPEED;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(floor(data->py - data->dir_y * MOVESPEED))]
	[(int)floor(data->px)] != '1')
		data->py -= data->dir_y * MOVESPEED;
	if (data->map[(int)(floor(data->py))]
	[(int)(floor(data->px - data->dir_x * MOVESPEED))] != '1')
		data->px -= data->dir_x * MOVESPEED;
}

void	move_leftward(t_data *data)
{
	if (data->map[(int)(floor(data->py))]
	[(int)(floor(data->px + data->dir_y * MOVESPEED))] == '0')
		data->px += data->dir_y * MOVESPEED;
	if (data->map[(int)(floor(data->py - data->dir_x * MOVESPEED))]
	[(int)(floor(data->px))] == '0')
		data->py -= data->dir_x * MOVESPEED;
}

void	move_rightward(t_data *data)
{
	if (data->map[(int)(floor(data->py))]
	[(int)(floor(data->px - data->dir_y * MOVESPEED))] == '0')
		data->px -= data->dir_y * MOVESPEED;
	if (data->map[(int)(floor(data->py + data->dir_x * MOVESPEED))]
	[(int)(floor(data->px))] == '0')
		data->py += data->dir_x * MOVESPEED;
}

void	ft_controls(t_data *data, int keycode)
{
	if (keycode == 13)
		move_forward(data);
	if (keycode == 1)
		move_backward(data);
	if (keycode == 0)
		move_leftward(data);
	if (keycode == 2)
		move_rightward(data);
	if (keycode == 123 || keycode == 124)
		ft_camera(data, keycode);
}
