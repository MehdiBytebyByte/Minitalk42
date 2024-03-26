/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexafunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:58 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/25 16:47:00 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

int	ft_hexaconv(unsigned int a, char c)
{
	int		count;
	char	*str;

	count = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (a < 16)
	{
		write (1, &str[a], 1);
		count++;
	}
	else
	{
		count += ft_hexaconv(a / 16, c);
		count += ft_hexaconv(a % 16, c);
	}
	return (count);
}

int	ft_hexapointer(unsigned long a)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789abcdef";
	if (a < 16)
	{
		write(1, &str[a], 1);
		count++;
	}
	else
	{
		count += ft_hexapointer(a / 16);
		count += ft_hexapointer(a % 16);
	}
	return (count);
}
