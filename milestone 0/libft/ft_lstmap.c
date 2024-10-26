/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:54:59 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/05 11:50:57 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*jason;

	newlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		jason = f(lst->content);
		if (jason != NULL)
			newnode = ft_lstnew(jason);
		if (!newnode || !jason)
		{
			ft_lstclear(&newlist, del);
			del(jason);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
