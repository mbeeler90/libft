/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:42:18 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/12 14:12:42 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelarray(void **ap)
{
	unsigned int	i;

	i = 0;
	while (ap[i])
	{
		ft_memdel(&ap[i]);
		i++;
	}
	free(ap);
}
