/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:54:39 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/25 16:47:04 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

int	ft_icheck(char c, va_list ap)
{
	int				count;
	unsigned long	p;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putnbr2(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_hexaconv(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		p = (unsigned long)va_arg(ap, void *);
		count += ft_hexapointer(p);
	}
	else if (c != '\0')
		count += write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			count += ft_icheck(*str, ap);
		}
		else
			count += write (1, str, 1);
		str++;
	}
	return (va_end (ap), count);
}
