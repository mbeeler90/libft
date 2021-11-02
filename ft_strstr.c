/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:41:54 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 18:41:57 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (to_find[i] == *str)
		{
			i++;
			str++;
			if (to_find[i] == '\0')
				return (str - i);
		}
		if (i == 0)
			str++;
		i = 0;
	}
	return (0);
}
