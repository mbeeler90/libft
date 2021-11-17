/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchangenew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:23:00 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 11:26:05 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstchangenew(t_list *lst)
{
	t_list	*ret;

	ret = ft_lstnew(lst->content, lst->content_size);
	ft_memset(ret->content, '!', 2);
	return (ret);
}
