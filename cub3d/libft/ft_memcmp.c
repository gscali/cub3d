/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:56:44 by tle               #+#    #+#             */
/*   Updated: 2021/03/25 10:04:27 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;

	i = 0;
	while (i < n)
	{
		res = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (res)
			return (res);
		i++;
	}
	return (0);
}
