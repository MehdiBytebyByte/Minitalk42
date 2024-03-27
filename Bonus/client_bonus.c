/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:08:06 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/26 21:48:55 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

size_t	ft_atoi(char *str)
{
	size_t	i;
	size_t	r;

	r = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if (r == 0)
		return (-1);
	return (r);
}

char	*convert(char c, char *table)
{
	int	i;

	i = 7;
	while (c != 0)
	{
		if (c % 2 != 0)
		{
			table[i] = '1';
			i--;
			c = c / 2;
		}
		else
		{
			table[i] = '0';
			i--;
			c = c / 2;
		}
	}
	return (table);
}

t_struct	init(t_struct a)
{
	int	i;

	i = 0;
	a.table[8] = '\0';
	while (i < 8)
		a.table[i++] = '0';
	return (a);
}

void	ft_sendsignal(t_struct a)
{
	int	i;
	int	j;

	i = 0;
	while (a.av2[i])
	{
		a = init(a);
		a.converted = convert(a.av2[i], a.table);
		j = 0;
		while (j < 8)
		{
			if (a.converted[j] == '1')
				kill(a.pid, SIGUSR2);
			if (a.converted[j] == '0')
				kill(a.pid, SIGUSR1);
			j++;
			usleep(2000);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_struct	a;

	ft_printf("my pid -->%d\n", getpid());
	a.av2 = argv[2];
	if (argc != 3)
	{
		printf("Please Enter 3 arguments");
		exit(EXIT_FAILURE);
	}
	a.pid = ft_atoi(argv[1]);
	if (a.pid == -1)
	{
		printf("Invalid pid \n");
		exit(EXIT_FAILURE);
	}
	ft_sendsignal(a);
	return (0);
}
