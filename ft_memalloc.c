/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:47:23 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/12 13:36:02 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void *) malloc(sizeof(void) * size);
	if (!ret)
		return (NULL);
	else
		return (ft_memset(ret, 0, size));
}
