/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:51:13 by tle               #+#    #+#             */
/*   Updated: 2021/03/31 14:50:17 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_size(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*convert(char *str, int size, int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		nbr = n * -1;
		i++;
	}
	else
		nbr = n;
	while (i < size)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*swap(char *str, int size)
{
	int		start;
	char	temp;

	start = 0;
	if (str[start] == '-')
	{
		while (start++ < size / 2)
		{
			temp = str[start];
			str[start] = str[size - start];
			str[size - start] = temp;
		}
	}
	else
	{
		while (start < size / 2)
		{
			temp = str[start];
			str[start] = str[size - 1 - start];
			str[size - 1 - start] = temp;
			start++;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = int_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str = convert(str, size, n);
	str = swap(str, size);
	return (str);
}
