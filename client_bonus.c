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

void	recev_it(int sig)
{
	(void)sig;
	ft_printf("😃 rah msg wssl 😃\n");
	exit(EXIT_SUCCESS);
}

void	send_it(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	int		l;

	if (argc == 3 && ft_isnmbr(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			exit(-1);
		i = 0;
		l = ft_strlen(argv[2]);
		signal(SIGUSR2, recev_it);
		while (i <= l)
		{
			send_it(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_printf("there is an error, raj3 nfsk !!");
		exit(-1);
	}
}
