/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:39:33 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:05:20 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char *) malloc(sizeof(*copy) * (len + 1));
	if (!copy)
		return (0);
	len = -1;
	while (src[++len] != '\0')
		copy[len] = src[len];
	copy[len] = '\0';
	return (copy);
}
