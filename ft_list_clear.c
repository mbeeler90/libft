/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:05 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:04:02 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*next_element;

	list = *begin_list;
	while (list)
	{
		next_element = list->next;
		free(list);
		list = next_element;
	}
	*begin_list = NULL;
}
