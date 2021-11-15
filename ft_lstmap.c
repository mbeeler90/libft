/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:27:24 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/15 18:44:14 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*iterated_list;
	t_list	*head;
	t_list	*new_element;

	if (!lst || !f)
		return (NULL);
	new_element = ft_lstnew((*f)(lst)->content, lst->content_size);
	lst = lst->next;
	iterated_list = new_element;
	head = iterated_list;
	while (lst)
	{
		ft_lstdelone(&new_element, &ft_lstclearelem);
		new_element = ft_lstnew((*f)(lst)->content, lst->content_size);
		iterated_list->next = new_element;
		iterated_list = iterated_list->next;
		lst = lst->next;
	}
	return (head);
}
