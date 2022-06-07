/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:40:28 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 19:10:06 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_param(char *s)
{
	if (!strncmp(s, "NO ", 3) || !strncmp(s, "SO ", 3)
		|| !strncmp(s, "WE ", 3) || !strncmp(s, "EA ", 3)
		|| !strncmp(s, "F ", 2) || !strncmp(s, "C ", 2))
		return (1);
	else
		ft_error("Error\nInvalid identifier\n");
	return (0);
}

char	*get_path(t_data *data, char *temp, char *path)
{
	int		i;
	int		len;
	char	*ret;

	if (path)
		ft_error("Error\nDuplicate identifier\n");
	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	if (!temp[i])
		ft_error("Error\nMissing path\n");
	len = ft_strlen(temp + i);
	ret = ft_substr(temp, i, len);
	data->param++;
	return (ret);
}

void	save_param(t_data *data, char *temp)
{
	if (!strncmp(temp, "NO ", 3))
		data->no = get_path(data, temp + 2, data->no);
	else if (!strncmp(temp, "SO ", 3))
		data->so = get_path(data, temp + 2, data->so);
	else if (!strncmp(temp, "WE ", 3))
		data->we = get_path(data, temp + 2, data->we);
	else if (!strncmp(temp, "EA ", 3))
		data->ea = get_path(data, temp + 2, data->ea);
	else if (!strncmp(temp, "F ", 2) || !strncmp(temp, "C ", 2))
		check_color(data, temp);
}

void	check_after(int fd)
{
	int		i;
	int		ret;
	char	*temp;

	ret = 1;
	while (ret > 0)
	{
		i = 0;
		get_next_line(fd, &temp);
		while (ft_isspace(temp[i]))
			i++;
		if (!temp[i])
			;
		else if (!ft_isdigit(temp[i]))
			ft_error("Error\nDuplicate identifier\n");
		else
			break ;
	}
}

void	parse_param(t_data *data, int fd)
{
	char	*temp;
	int		ret;
	int		i;

	ret = 1;
	while (data->param != 6 && ret > 0)
	{
		i = 0;
		ret = get_next_line(fd, &temp);
		while (ft_isspace(temp[i]))
			i++;
		if (temp[i] == '\n' || temp[i] == '\0')
			;
		else if (temp[i] == '1')
			break ;
		else if (check_param(temp + i))
			save_param(data, temp + i);
		free(temp);
	}
	if (data->param != 6)
		ft_error("Error\nMissing parameter(s)\n");
	check_path(data);
}
