/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:04 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/26 18:23:20 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

t_server	g_a = {0, 0, 0};

void	deepersighandle(int signum, siginfo_t *info, void *ptr)
{
	if (g_a.pid != info->si_pid)
	{
		g_a.pid = info->si_pid;
		g_a.byte = 0;
		g_a.bit_count = 0;
	}
	if (signum == SIGUSR1)
	{
		g_a.byte = (g_a.byte << 1);
		g_a.bit_count++;
	}
	else if (signum == SIGUSR2)
	{
		g_a.byte = (g_a.byte << 1) | 1;
		g_a.bit_count++;
	}
	if (g_a.bit_count == 8)
	{
		ft_printf("%c", g_a.byte);
		g_a.byte = 0;
		g_a.bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("This server PID is ->%d\n", getpid());
	sa.__sigaction_u.__sa_sigaction = deepersighandle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
