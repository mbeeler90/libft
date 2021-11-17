/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:38:43 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 13:33:15 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (s && f && ret)
	{
		while (s[i] != '\0')
		{
			ret[i] = (*f)(s[i]);
			i++;
		}
	}
	return (ret);
}
