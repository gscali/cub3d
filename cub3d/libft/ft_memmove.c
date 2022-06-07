/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:57:23 by tle               #+#    #+#             */
/*   Updated: 2021/03/31 14:57:05 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	dest = (unsigned char *) dst;
	str = (unsigned char *) src;
	if (!dest && !str)
		return (NULL);
	if (dest > str)
	{
		while (len-- > 0)
			dest[len] = str[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	return (dst);
}
