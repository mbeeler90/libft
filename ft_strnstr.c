/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:12:49 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/08 11:27:31 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (j < len)
	{
		while (needle[i] == haystack[j] && j < len)
		{
			i++;
			j++;
			if (needle[i] == '\0')
				return ((char *) haystack + j - i);
		}
		if (i == 0)
			j++;
		else
			i = 0;
	}
	return (NULL);
}
