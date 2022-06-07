/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:10:09 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 19:10:04 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_arg(char *arg, char *ext)
{
	int	len;

	if (!ft_strncmp(arg, ext, 4))
		return (1);
	len = ft_strlen(arg);
	if (len > 4)
		len -= 4;
	arg = ft_substr(arg, len, 4);
	if (ft_strnstr(arg, ext, 4))
	{
		free((char *)arg);
		return (0);
	}
	free((char *)arg);
	return (1);
}

void	ft_parse(t_data *data)
{
	int	fd;

	fd = open(data->arg, O_DIRECTORY);
	if (fd != -1)
		ft_error("Error\nNot a file\n");
	fd = open(data->arg, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFile not found\n");
	if (parse_arg(data->arg, ".cub"))
		ft_error("Error\nNot a .cub file\n");
	parse_param(data, fd);
	parse_map(data, fd);
}
