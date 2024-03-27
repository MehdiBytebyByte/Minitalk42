/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:04 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/27 23:39:28 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

void reset(unsigned char *byte, int *bit_count)
{
	*byte = 0;
	*bit_count = 0;
}

void	deepersighandle(int signum, siginfo_t *info, void *ptr)
{
	static int pid;
	static unsigned char byte;
	static int bit_count;
	
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		reset(&byte, &bit_count);
	}
	byte = (byte << 1) | (signum - SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", byte);
		reset(&byte, &bit_count);
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
