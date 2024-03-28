/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:04 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/28 06:31:52 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

void reset(unsigned char *str, int *i, int *j, int *expected)
{
	int r;

	r = 0;
	*i = 0;
	*j = 0;
	*expected = 0;
	while (r < 4)
	{
		str[r++] = 0;
	}
}

int check(unsigned char byte)
{
	if (byte >= 240)
		return(32);
	else if (byte >= 224)
		return(24);
	else if (byte >= 192)
		return(16);
	else
		return (8);
}
void iprint(unsigned char *str, int *expected, int *i, int *j)
{
	int r;
	int bytelen = *expected / 8;

	r = 0;
	while (r < bytelen)
	{
		ft_printf("%c",str[r]);
		r++;
	}
	reset(str, i, j, expected);
}

void	deepersighandle(int signum, siginfo_t *info, void *ptr)
{
	static int				pid;
	static unsigned char	byte[4];
	static int 				i;
	static int				j;
	static int				expected;
	
	(void)*ptr;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		reset(byte, &i, &j, &expected);
	}
	byte[j] = (byte[j] << 1) | (signum - SIGUSR1);
	i++;
	if (i == 8)
	{
		i = 0;
		if (j == 0)
			expected = check(byte[0]);
		j++;	
	}
	if ((8 * j + i) == expected)
        iprint(byte, &expected, &i, &j);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("This server PID is ->%d\n", getpid());
	sa.sa_sigaction = deepersighandle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
