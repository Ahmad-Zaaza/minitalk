/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:33:15 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 23:17:57 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile int i = 0;

static void ft_btoa(int sig) {
  static int bit;

  if (sig == SIGUSR1)
    i = (i << 1);
  if (sig == SIGUSR2)
    i = (i << 1) | 1;

  bit++;
  if (bit == 8) {
    ft_printf("%c", i);
    bit = 0;
    i = 0;
  }
}

static void signal_handler(int sig) {

  if (sig == SIGUSR1) {
    ft_printf("SIGUSR1 received %d,...\n", sig);
  }
  if (sig == SIGUSR2) {
    ft_printf("SIGUSR2 received %d,...\n", sig);
  }
}

int main(void) {

  pid_t pid;
  struct sigaction sa;

  pid = getpid();
  sa.sa_handler = ft_btoa;
  sa.sa_flags = SA_RESTART;
  sigemptyset(&sa.sa_mask);

  ft_printf("%d\n", pid);
  ft_printf("Server started...\n");
  while (1) {
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
      ft_printf("Error: cannot handle Signal\n");
      exit(1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
      ft_printf("Error: cannot handle Signal\n");
      exit(1);
    }
  }

  return (0);
}
