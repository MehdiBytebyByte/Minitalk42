/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:40:29 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/28 03:02:23 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_struct
{
	pid_t	pid;
	char			table[9];
	char			*av2;
	char			*converted;
}	t_struct;

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putnbr2(long n);
int	ft_putstr(char *s);
int	ft_hexaconv(unsigned int a, char c);
int	ft_hexapointer(unsigned long a);

#endif