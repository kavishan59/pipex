/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:19:09 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 15:28:41 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*first;
	t_list	*current;

	first = NULL;
	current = NULL;
	if (!lst || !(*f) || !(*del))
		return (NULL);
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&first, current);
		if (!current)
			ft_lstclear(&first, del);
		lst = lst->next;
	}
	return (first);
}
