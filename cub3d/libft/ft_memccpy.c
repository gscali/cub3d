/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:45:55 by tle               #+#    #+#             */
/*   Updated: 2021/03/26 13:39:10 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dest;
	unsigned char	l;

	i = 0;
	str = (unsigned char *) src;
	dest = (unsigned char *) dst;
	l = (unsigned char) c;
	while (i < n)
	{
		dest[i] = str[i];
		if (str[i] == l)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
