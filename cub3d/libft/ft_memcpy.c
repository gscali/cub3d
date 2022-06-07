/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:05:28 by tle               #+#    #+#             */
/*   Updated: 2021/03/31 14:55:47 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dest;

	i = 0;
	str = (unsigned char *) src;
	dest = (unsigned char *) dst;
	if (!dest && !str)
		return (NULL);
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
