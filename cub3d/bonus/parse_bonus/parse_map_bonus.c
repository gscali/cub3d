/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:55:02 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 20:11:08 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	skip_space(int fd)
{
	int		ret;
	int		i;
	char	*temp;

	ret = 1;
	i = 0;
	temp = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &temp);
		while (ft_isspace(temp[i]))
			i++;
		if (!temp[i])
			;
		else if (!ft_isdigit(temp[i]))
			ft_error("Error\nDuplicate identifier\n");
		else
			break ;
		free(temp);
	}
	if (!temp[i])
		ft_error("Error\nMap is empty\n");
	free(temp);
	return (1);
}

char	*get_map(int fd)
{
	int		ret;
	char	*temp;
	int		i;

	ret = 1;
	while (ret > 0)
	{
		i = 0;
		ret = get_next_line(fd, &temp);
		while (ft_isspace(temp[i]))
			i++;
		if (ft_isdigit(temp[i]))
			break ;
		free(temp);
	}
	return (temp);
}

void	save_map(t_data *data, int size)
{
	int	fd;
	int	ret;
	int	i;

	i = 1;
	ret = 1;
	data->map = malloc(sizeof(char *) * (size + 1));
	fd = open(data->arg, O_RDONLY);
	free(data->arg);
	data->map[0] = get_map(fd);
	while (ret > 0)
	{
		ret = get_next_line(fd, &data->map[i]);
		i++;
	}
	data->map[i] = NULL;
}

void	parse_map(t_data *data, int fd)
{
	int		ret;
	int		size;
	char	*temp;

	size = 0;
	ret = 1;
	size = skip_space(fd);
	while (ret > 0)
	{
		ret = get_next_line(fd, &temp);
		if (!temp[0])
			ft_error("Error\nEmpty line in map\n");
		free(temp);
		size++;
	}
	data->size = size - 1;
	save_map(data, size);
	check_map(data);
}
