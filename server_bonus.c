/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:42:33 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/04/15 01:48:54 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_kch	g_mini;

void	initialization(void)
{
	g_mini.bit = 0;
	g_mini.pid = 0;
	g_mini.c = 0;
}

void	hundle_it(int sig, siginfo_t *si, void *context)
{
	(void)context;
	if (si->si_pid != g_mini.pid)
		initialization();
	g_mini.c += ((sig & 1) << g_mini.bit);
	g_mini.bit++;
	if (g_mini.bit == 8)
	{
		ft_printf("%c", g_mini.c);
		if (!g_mini.c)
		{
			kill(si->si_pid, SIGUSR2);
		}
		initialization();
	}
	g_mini.pid = si->si_pid;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = hundle_it;
	sa.sa_flags = SA_RESTART;
	ft_printf("ha Lpid :%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
