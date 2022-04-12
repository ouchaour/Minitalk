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
	if (sig == SIGUSR1)
		ft_printf("rah msg wssl\n");
}

void	send_it(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((128 >> i) & c)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
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
		signal(SIGUSR1, recev_it);
		// WA AKHI TALIB , WA HADCHI TAL BOUNUS 7YD HD L9LAWI WA CHOKRAN
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
