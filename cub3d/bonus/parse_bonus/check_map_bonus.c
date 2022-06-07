/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:37:57 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 20:46:43 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!valid_char(data->map[i][j]))
				ft_error("Error\nInvalid character in map\n");
			j++;
		}
		i++;
	}
}

void	check_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ' && !valid_space(data, i, j))
				ft_error("Error\nMap is not closed\n");
			if (is_player(data->map[i][j]))
			{
				if (data->py || data->px)
					ft_error("Error\nToo much starting position\n");
				data->px = (double)j + 0.5;
				data->py = (double)i + 0.5;
				data->direction = data->map[i][j];
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ')
			j++;
		if (data->map[i][j] != '1'
			|| data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			ft_error("Error\nMap is not closed\n");
		if (i == 0 || i == data->size)
		{
			while (data->map[i][j])
			{	
				if (data->map[i][j] != '1')
					ft_error("Error\nMap is not closed\n");
				j++;
			}
		}
		i++;
	}
}

void	check_len(t_data *data)
{
	int	i;
	int	j;
	int	excess;

	i = 0;
	while (data->map[i])
	{
		j = ft_strlen(data->map[i]) - 1;
		if (data->map[i + 1] && j > (ft_strlen(data->map[i + 1] - 1)))
		{
			excess = j - (ft_strlen(data->map[i + 1]) - 1);
			while (excess)
			{
				if (excess < 0)
					break ;
				if (data->map[i][j] == '0' || data->map[i][j] == 'N'
					|| data->map[i][j] == 'S' || data->map[i][j] == 'W'
						|| data->map[i][j] == 'E')
					ft_error("Error\nMap is not closed\n");
				j--;
				excess--;
			}
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	check_character(data);
	check_content(data);
	check_len(data);
	check_wall(data);
}
