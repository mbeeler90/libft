/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:39:33 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/04 16:42:44 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *) malloc(sizeof(*copy) * (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	return (ft_strcpy(copy, s1));
}
