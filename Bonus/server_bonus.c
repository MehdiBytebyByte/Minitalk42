/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:04 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/27 17:11:20 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minitalk.h"

void	reset(unsigned char* str,int *count)
{
	int i;

	*count = 0;
	i = 0;
	while (i < 4)
		str[i++] = 0;
}
int	counter(unsigned char c)
{
	if(c >= 240)
		return (32);
	else if(c >= 224)
		return (24);
	else if(c >= 192)
		return (16);
	else
		return(8);
}

void	deepersighandle(int signum, siginfo_t *info, void *ptr)
{
	static int				pid;
	static unsigned char	bytes[4];
	static int				count;
	static int				i;
	static int				expected;
	
	// if (pid != info->si_pid)
	// {
	// 	reset(bytes, &count);
	// 	pid = info->si_pid;
	// }
	if (signum == SIGUSR1)
	{
		write(1,"0",1);
		bytes[i] = (bytes[i] << 1);
	}
	else if (signum == SIGUSR2)
	{
		write(1,"1",1);
		bytes[i] = (bytes[i] << 1) | 1;	
	}
	count++;
	if (count == 8)
	{
		printf("%d",bytes[i]);
		exit(1);
		expected = counter(bytes[i]);
		if (expected == 8)
			{
			}
		else
		{

		}
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


//11111111