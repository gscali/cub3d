/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:55:02 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 19:10:09 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_tab(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		free(data->no);
		free(data->so);
		free(data->ea);
		free(data->we);
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}
