/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:59:03 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 20:16:49 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	save_rgb(t_data *data, int count, char *temp, int *i)
{
	if (data->type == 'F')
	{	
		data->floor[count] = ft_atoi(temp, i);
		data->f_done = 1;
	}
	else
	{	
		data->ceiling[count] = ft_atoi(temp, i);
		data->c_done = 1;
	}
}

void	path_valid(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
		ft_error("Error\nPath is a directory\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nPath not found\n");
	close(fd);
}

void	check_path(t_data *data)
{
	if (parse_arg(data->no, ".xpm") || parse_arg(data->so, ".xpm")
		|| parse_arg(data->we, ".xpm") || parse_arg(data->ea, ".xpm"))
		ft_error("Error\nPath is not a .xpm file\n");
	path_valid(data->no);
	path_valid(data->so);
	path_valid(data->we);
	path_valid(data->ea);
}
