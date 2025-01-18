/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taabu-fe <taabu-fe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:24:17 by taabu-fe          #+#    #+#             */
/*   Updated: 2025/01/18 12:30:37 by taabu-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_sig = 0;

void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		g_sig = 1;
}

void	send_null(int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		g_sig = 0;
		kill(pid, SIGUSR1);
		while (!g_sig)
			;
		j++;
	}
	ft_putstr_fd("COMPLETE SENDING\n", 1);
}

void	send_util(int ch, int pid)
{
	if (ch == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("PID ERROR :)\n", 2);
			return ;
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("PID ERROR :)\n", 2);
			return ;
		}
	}
}

void	send(char *str, int pid)
{
	int	i;
	int	j;
	int	ch;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			ch = (str[i] >> j) & 1;
			g_sig = 0;
			send_util(ch, pid);
			while (!g_sig)
				;
			j++;
		}
		i++;
	}
	send_null(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
		return (1);
	sa.sa_flags = 0;
	sa.sa_handler = sig_handle;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
	{
		ft_putstr_fd("PID ERROR :)\n", 2);
		exit(1);
	}
	send(argv[2], pid);
}
