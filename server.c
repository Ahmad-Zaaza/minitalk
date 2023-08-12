/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:33:15 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/10 23:56:25 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig) {
  if (sig == SIGINT) {
    printf("Caught signal %d, coming out...\n", sig);
    exit(1);
  }
  if (sig == SIGUSR1) {
    printf("SIGUSR1 received %d,...\n", sig);
  }
}

int main(void) {

  pid_t pid;
  struct sigaction sa;

  pid = getpid();
  sa.sa_handler = signal_handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaddset(&sa.sa_mask, SIGUSR1);

  if (sigaction(SIGINT, &sa, NULL) == -1) {
    printf("Error: cannot handle Signal\n");
    exit(1);
  }

  printf("%d\n", pid);
  printf("Server started...\n");
  while (1) {
  }

  return (0);
}
