/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:49:24 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:49:19 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_tab(data);
	ft_error("Window closed\n");
	return (0);
}

int	map_loop(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	ft_dda(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	detect_key(int keycode, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_tab(data);
		ft_error("ESC key detected\n");
	}
	ft_controls(data, keycode);
	return (0);
}

void	ft_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
		data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	xpm_to_img(data);
	data->floor_rgb = get_rgb(data->floor[0], data->floor[1], data->floor[2]);
	data->ceiling_rgb = get_rgb(data->ceiling[0],
			data->ceiling[1], data->ceiling[2]);
	mlx_hook(data->win_ptr, 17, 0, close_win, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, detect_key, data);
	mlx_loop_hook(data->mlx_ptr, map_loop, data);
	mlx_loop(data->mlx_ptr);
}
