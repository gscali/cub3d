/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:40:05 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 19:36:24 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_data *data, char **av)
{
	data->param = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->c_done = 0;
	data->f_done = 0;
	data->arg = ft_strdup(av[1]);
	data->map = NULL;
	data->size = 0;
	data->px = 0;
	data->py = 0;
	data->dir_x = 0;
	data->dir_y = 0;
	data->field_x = 0;
	data->field_y = 0;
}

void	init_position(t_data *data)
{
	if (data->direction == NORTH)
	{
		data->dir_y = -1.0001;
		data->field_x = 0.6;
	}
	else if (data->direction == SOUTH)
	{
		data->dir_y = 1.0001;
		data->field_x = -0.6;
	}
	else if (data->direction == WEST)
	{
		data->dir_x = -1.0001;
		data->field_y = -0.6;
	}
	else if (data->direction == EAST)
	{
		data->dir_x = 1.0001;
		data->field_y = 0.6;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("Error\nInvalid format\n");
	init_struct(&data, av);
	ft_parse(&data);
	init_position(&data);
	ft_mlx(&data);
}
