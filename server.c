/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:42:33 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/04/07 02:42:39 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signall(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	hundle_it(int signum, siginfo_t *si, void *hh)
{
	static char	c = 0xff;
	static int	bit = 0;
	static int	pid;

	(void)hh;
	if (si->si_pid)
		pid = si->si_pid;
	if (signum == SIGUSR1)
		c |= 128 >> bit;
	else if (signum == SIGUSR2)
		c ^= 128 >> bit;
	bit++;
	if (bit == 8)
	{
		if (!c)
		{
			signall(SIGUSR1, pid);
		}
		ft_printf("%c", c);
		bit = 0;
		c = 0xff;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = hundle_it;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("ha Lpid :%d\n", pid);
	while (1)
	{
		sleep(1);
	}
}
