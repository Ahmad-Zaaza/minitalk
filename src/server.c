/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:33:15 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 15:20:07 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main(void) {

  pid_t pid;
  struct sigaction sa;

  pid = getpid();
  sa.sa_handler = signal_handler;
  sa.sa_flags = SA_RESTART;
  sigemptyset(&sa.sa_mask);

  if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    printf("Error: cannot handle Signal\n");
    exit(1);
  }
  if (sigaction(SIGUSR2, &sa, NULL) == -1) {
    printf("Error: cannot handle Signal\n");
    exit(1);
  }

  printf("%d\n", pid);
  printf("Server started...\n");
  while (1) {
  }

  return (0);
}
