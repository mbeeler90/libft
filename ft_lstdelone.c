/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:24:50 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 10:09:34 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && *del)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **) alst);
	}
}
