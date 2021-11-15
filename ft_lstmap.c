/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:27:24 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/15 19:25:47 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new_element;

	if (!lst || !f)
		return (NULL);
	new_element = (*f)(lst);
	lst = lst->next;
	head = new_element;
	while (lst)
	{
		new_element->next = (*f)(lst);
		new_element = new_element->next;
		lst = lst->next;
	}
	return (head);
}
