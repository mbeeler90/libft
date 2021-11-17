/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:53:49 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 13:18:12 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *) src;
	str2 = (char *) dst;
	if (str2 > str1)
	{
		i = len;
		while (i-- > 0)
			str2[i] = str1[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			str2[i] = str1[i];
			i++;
		}
	}
	str2[len] = '\0';
	return (dst);
}
