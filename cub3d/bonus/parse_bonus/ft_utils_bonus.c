/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:10:00 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 20:10:54 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(EXIT_FAILURE);
}

int	ft_tablen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ')
		return (1);
	return (0);
}

int	valid_space(t_data *data, int i, int j)
{
	if ((j == 0 || data->map[i][j - 1] == ' ' || data->map[i][j - 1] == '1')
		&& (!data->map[i][j + 1] || data->map[i][j + 1] == ' '
			|| data->map[i][j + 1] == '1')
		&& (i == 0 || data->map[i - 1][j] == ' ' | data->map[i - 1][j] == '1')
		&& (!data->map[i + 1] || data->map[i + 1][j] == ' '
			|| data->map[i + 1][j] == '1'))
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
