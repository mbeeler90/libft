/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:30:37 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/17 13:45:00 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_neg(int *n, int *sign)
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

int	ft_measure_length(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		n2;
	char	*ret;

	sign = 0;
	ft_check_neg(&n, &sign);
	len = ft_measure_length(n) + 1;
	len += sign;
	ret = ft_strnew((size_t) len);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (--len >= sign)
	{
		ret[len] = '0' + (n % 10);
		n /= 10;
	}
	if (sign > 0)
		ret[0] = '-';
	if (sign == 2)
		ret[1] = '2';
	return (ret);
}
