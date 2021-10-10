/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsenal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:41 by harsenal          #+#    #+#             */
/*   Updated: 2021/10/05 15:55:52 by harsenal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_databox;

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_one(int signum)
{
	(void)signum;
	g_databox.priem += g_databox.mask;
	g_databox.mask /= 2;
}

void	ft_null(int signum)
{
	(void)signum;
	g_databox.mask /= 2;
}

void	ft_collector(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		ft_null(SIGUSR1);
		usleep(50);
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (signal == SIGUSR2)
	{
		ft_one(SIGUSR2);
		usleep(50);
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (g_databox.mask == 0 && g_databox.priem != '\0')
	{
		ft_print_char(g_databox.priem);
		g_databox.mask = 128;
		g_databox.priem = 0;
	}
	if (g_databox.mask == 0 && g_databox.priem == '\0')
	{
		ft_print_char('\n');
		g_databox.mask = 128;
		g_databox.priem = 0;
	}
}

int	main(int argc, char	*argv[])
{
	struct sigaction	ft_sig;
	int					pid;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_printf("Server PID  = %d\n", pid);
	ft_sig.sa_flags = SA_SIGINFO;
	ft_sig.sa_sigaction = ft_collector;
	if (sigaction (SIGUSR1, &ft_sig, NULL) == -1)
		ft_printf("Sigaction error!\n");
	if (sigaction (SIGUSR2, &ft_sig, NULL) == -1)
		ft_printf("Sigaction error!\n");
	g_databox.priem = 0;
	g_databox.mask = 128;
	while (1)
		pause();
	return (0);
}
