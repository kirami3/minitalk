/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsenal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:32:24 by harsenal          #+#    #+#             */
/*   Updated: 2021/10/05 15:50:26 by harsenal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_databox;

void	ft_action(int sig)
{
	(void)sig;
	usleep(45);
}

void	ft_error_7(void)
{
	if (g_databox.ret != 0)
	{
		ft_printf("Error sending. Incorrect PID\n");
		exit (0);
	}
}

void	ft_send_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(45);
		kill(pid, SIGUSR1);
		i++;
		pause();
	}
}

void	ft_send_msg(int pid, char *str)
{
	int	b;

	b = 128;
	while (*str)
	{
		while (b > 0)
		{
			usleep(45);
			if (*str & b)
				g_databox.ret = kill(pid, SIGUSR2);
			else
				g_databox.ret = kill(pid, SIGUSR1);
			ft_error_7();
			pause();
			b /= 2;
		}
		b = 128;
		str++;
	}
	ft_send_end(pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal (SIGUSR1, ft_action);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send_msg (pid, argv[2]);
	}
	return (0);
}
