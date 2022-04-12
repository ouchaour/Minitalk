/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:50:54 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/04/11 22:58:52 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

int		ft_strlen(char *s);
int		ft_isnmbr(char *str);
int		ft_atoi(char *str);
void	handler(int signum, siginfo_t *si, void *hh);
void	send_it(char c, int pid);

#endif
