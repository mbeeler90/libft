/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeeler <mbeeler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:13:29 by mbeeler           #+#    #+#             */
/*   Updated: 2021/11/05 16:21:21 by mbeeler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen((const char *) dst);
	if (dstsize > len + 1 && sizeof(dst) >= dstsize)
		ft_strncat(dst, src, (dstsize - len - 1));
	return (len + ft_strlen(src));
}
