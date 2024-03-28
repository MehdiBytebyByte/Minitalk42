/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:40:29 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/28 16:12:02 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	pid_t			pid;
	char			table[9];
	char			*av2;
	char			*converted;
}	t_struct;

int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
int			ft_putnbr(long n);
int			ft_putnbr2(long n);
int			ft_putstr(char *s);
int			ft_hexaconv(unsigned int a, char c);
int			ft_hexapointer(unsigned long a);
void		recieved(int i);
void		deepersighandlem(int signum, siginfo_t *info, void *ptr);
void		deepersighandle(int signum, siginfo_t *info, void *ptr);
void		reset(unsigned char *byte, int *bit_count);
int			ft_sendsignal(t_struct a);
t_struct	init(t_struct a);
char		*convert(char c, char *table);
pid_t		ft_atoi(char *str);
void		iprint(unsigned char *str, int *expected, int *i, int *j);
int			check(unsigned char byte);
void		resetb(unsigned char *str, int *i, int *j, int *expected);
char		*convertb(char c, char *table);

#endif