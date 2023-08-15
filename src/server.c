/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:33:15 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/15 19:46:24 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_byte = 0;

void	send_acknowledgement(int pid)
{
	if (kill(pid, ACKNOWLEDGE_SIG) == -1)
	{
		ft_printf("🚨 Error: cannot send acknowledgement\n");
		exit(1);
	}
}

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	bit_count;

	(void)context;
	if (sig == SIGUSR1)
		g_byte = (g_byte << 1);
	if (sig == SIGUSR2)
		g_byte = (g_byte << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (g_byte == '\0')
			send_acknowledgement(siginfo->si_pid);
		ft_printf("%c", g_byte);
		bit_count = 0;
		g_byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("📨 Ready to listen...\n");
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("🚨 Error: cannot handle Signal SIGUSR1\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("🚨 Error: cannot handle Signal SIGUSR2\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
