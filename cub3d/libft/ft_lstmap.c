/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:48:49 by tle               #+#    #+#             */
/*   Updated: 2021/04/01 16:24:51 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*tab;
	t_list	*copy;
	void	*content;

	tab = NULL;
	while (lst)
	{
		content = f(lst->content);
		copy = ft_lstnew(content);
		if (!copy)
		{
			ft_lstclear(&tab, del);
			return (NULL);
		}
		ft_lstadd_back(&tab, copy);
		lst = lst->next;
	}
	return (tab);
}
