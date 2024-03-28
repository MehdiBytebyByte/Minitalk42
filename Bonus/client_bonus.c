/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:08:06 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/28 00:37:42 by mboughra         ###   ########.fr       */
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
	while (str[i])
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if (r <= 0 || r > 99999)
		return (-1);
	return (r);
}

char	*convert(char c, char *table)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c % 2 != 0)
			table[i] = '1';
		else
			table[i] = '0';
		c = (c >> 1);
		i--;
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

int	ft_sendsignal(t_struct a)
{
	int	i;
	int	j;

	i = 0;
	while (a.av2[i])
	{
		a = init(a);
		a.converted = convert(a.av2[i], a.table);
		printf("%s\n",a.converted);
		j = 0;
		while (j < 8)
		{
			if (a.converted[j] == '1')
				if ((kill(a.pid, SIGUSR2)) == -1)
					return(-1);
			if (a.converted[j] == '0')
				if ((kill(a.pid, SIGUSR1)) == -1)
					return(-1);
			j++;
			usleep(900);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_struct	a;

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
	if(ft_sendsignal(a) == -1)
		ft_printf("Pid wrong or Kill function failled");
	return (0);
}


// 00010000
// 01100001
// 01011100
// 01101010

//11110000 10011111 10100100 10010110