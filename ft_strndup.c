/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:07:00 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/26 20:10:54 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*copy;

	if (len > ft_strlen(s1))
		len = ft_strlen(s1);
	copy = (char *) malloc(len + 1);
	if (!copy)
		return (NULL);
	return (ft_strmove(copy, s1, len));
}
