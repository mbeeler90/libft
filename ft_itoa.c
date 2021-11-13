/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:30:37 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/12 15:42:16 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_neg(int *n, int *sign)
{
	if (*n < 0)
	{
		*sign = 1;
		if (*n == -2147483648)
		{
			*sign = 2;
			*n = 147483648;
		}
		else
			*n *= -1;
	}
	return (*n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		n2;
	char	*ret;

	len = 1;
	sign = 0;
	n2 = ft_check_neg(&n, &sign);
	while ((n /= 10) > 0)
		len++;
	len += sign;
	ret = ft_strnew((size_t) len);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (--len >= sign)
	{
		ret[len] = '0' + (n2 % 10);
		n2 /= 10;
	}
	if (sign > 0)
		ret[0] = '-';
	if (sign == 2)
		ret[1] = '2';
	return (ret);
}
