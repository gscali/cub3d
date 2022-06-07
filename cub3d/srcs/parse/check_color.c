/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:38:58 by tle               #+#    #+#             */
/*   Updated: 2022/01/27 20:14:29 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_digit(char *temp, int i)
{
	int	j;

	j = i;
	while (temp[j] && j < i + 3)
	{
		if (temp[j] == ',' || ft_isspace(temp[j]))
			return (1);
		if (temp[j] == '-')
			i++;
		else if (temp[j] < '0' || temp[j] > '9')
			ft_error("Error\nColor is not a number\n");
		j++;
	}
	return (1);
}

void	start_check(char *temp, int *i)
{
	while (ft_isspace(temp[*i]))
		(*i)++;
	if (!temp[*i] || !ft_digit(temp, *i))
		ft_error("Error\nMissing color\n");
	if (!ft_isdigit(temp[(*i)]))
		ft_error("Error\nFirst number is not digit\n");
}

void	end_check(char *temp, int *i, int count)
{
	while (temp[*i] && ft_isspace(temp[*i]))
		(*i)++;
	if (count < 2 && (temp[*i] == ',' || ft_isspace(temp[*i])))
		(*i)++;
	else if ((count < 2 && (temp[*i] != ',' || !ft_isspace(temp[*i]))))
		ft_error("Error\nNot enough number(s)\n");
	else if ((count == 2 && (temp[*i] == ',' || ft_isspace(temp[*i]))))
		ft_error("Error\nToo many number(s)\n");
}

void	check_type(t_data *data, char type, int count)
{	
	if ((type == 'F' && (data->floor[count] < 0
				|| data->floor[count] > 255))
		|| (type == 'C' && (data->ceiling[count] < 0
				|| data->ceiling[count] > 255)))
		ft_error("Error\nToo low/too high number\n");
}

void	check_color(t_data *data, char *temp)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (ft_isspace(temp[i]))
		i++;
	data->type = temp[i++];
	if ((data->type == 'C' && data->c_done)
		|| (data->type == 'F' && data->f_done))
		ft_error("Error\nDuplicate identifier\n");
	while (count < 3)
	{
		start_check(temp, &i);
		save_rgb(data, count, temp, &i);
		check_type(data, data->type, count);
		end_check(temp, &i, count);
		count++;
	}
	data->param++;
}
