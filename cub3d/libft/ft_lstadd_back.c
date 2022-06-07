/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:21:37 by tle               #+#    #+#             */
/*   Updated: 2021/04/01 13:54:41 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tab;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tab = *alst;
		while (tab->next != NULL)
			tab = tab->next;
		tab->next = new;
	}
}
