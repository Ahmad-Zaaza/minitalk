/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:33:15 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/14 01:35:06 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int byte = 0;

void send_acknowledgement(int pid) {
  if (kill(pid, SIGUSR1) == -1)
    ft_printf("🚨 Error: cannot send acknowledgement\n");
  exit(1);
}

void handle_signal(int sig, siginfo_t *siginfo, void *context) {
  static int bit_count;

  (void)context;
  if (sig == SIGUSR1)
    byte = (byte << 1);
  if (sig == SIGUSR2)
    byte = (byte << 1) | 1;

  bit_count++;
  // if byte is complete
  if (bit_count == 8) {
    // If the client sends a null byte, it means that the message is complete
    if (byte == '\0')
      send_acknowledgement(siginfo->si_pid); // si_pid is the client's pid
    ft_printf("%c", byte);
    // reset bit_count and i
    bit_count = 0;
    byte = 0;
  }
}

int main(void) {
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = handle_signal;

  ft_printf("Server PID: %d\n", getpid());
  ft_printf("📨 Ready to listen...\n");

  if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    ft_printf("🚨 Error: cannot handle Signal SIGUSR1\n");
    exit(1);
  }
  if (sigaction(SIGUSR2, &sa, NULL) == -1) {
    ft_printf("🚨 Error: cannot handle Signal SIGUSR2\n");
    exit(1);
  }

  while (1)
    pause();

  return (0);
}
