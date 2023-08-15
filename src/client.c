/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:41:10 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/15 20:00:34 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_invalid_pid(void)
{
	ft_printf("🚨 Error: Invalid server PID\n");
	exit(1);
}

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (sig == ACKNOWLEDGE_SIG)
		ft_printf("📨 Message received by server\n");
	else
	{
		ft_printf("🚨 There was an error while");
		ft_printf("recieving acknowledgment from the server \n");
	}
}

void	send_signal(int *bits, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bits[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
	free(bits);
}

void	*transform_and_send(int c, int pid)
{
	int	*bits;
	int	size;
	int	letter;

	size = 8;
	bits = calloc(size, sizeof(int));
	if (!bits)
		return (NULL);
	letter = c;
	while (size > 0)
	{
		bits[size - 1] = letter & 1;
		letter = letter >> 1;
		size--;
	}
	send_signal(bits, pid);
	return (bits);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	int					i;

	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments,");
		ft_printf("use ./client <server_pid> <your_message> \n");
		exit(1);
	}
	if (!is_numeric(argv[1]) || ft_strcmp(argv[1], "0") == 0)
		print_invalid_pid();
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("🚨 Error: cannot handle Signal SIGUSR1\n");
		exit(1);
	}
	i = 0;
	while (argv[2][i])
		transform_and_send(argv[2][i++], pid);
	transform_and_send('\n', pid);
	transform_and_send('\0', pid);
	return (0);
}
