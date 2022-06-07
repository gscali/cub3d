/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:58:28 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 20:06:44 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_camera(t_data *data, int keycode)
{
	float	old_dir;
	float	old_field;
	float	rot;

	rot = 0.1;
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			rot *= -1;
		old_dir = data->dir_x;
		old_field = data->field_x;
		data->dir_x = data->dir_x * cos(rot) - data->dir_y * sin(rot);
		data->dir_y = old_dir * sin(rot) + data->dir_y * cos(rot);
		data->field_x = data->field_x * cos(rot) - data->field_y * sin(rot);
		data->field_y = old_field * sin(rot) + data->field_y * cos(rot);
	}
}
