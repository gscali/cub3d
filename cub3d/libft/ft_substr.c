/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:58:16 by tle               #+#    #+#             */
/*   Updated: 2021/04/01 17:39:37 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	letter_count(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s + start) > (int)len)
		return (len);
	else
		return (ft_strlen(s + start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if ((int)start < ft_strlen(s))
		str = (char *)malloc(sizeof(char) * letter_count(s, start, len) + 1);
	else
		str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	*str = 0;
	if ((int)start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}
