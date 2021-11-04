/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:09:34 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/04 14:58:23 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *) src;
	str2 = (char *) dst;
	while (i < n)
	{
		str2[i] = str1[i];
		if (str1[i] == (char) c)
		{
			i++;
			str2[i] = '\0';
			return (dst + i + 1);
		}
		i++;
	}
	str2[i] = '\0';
	return (NULL);
}
