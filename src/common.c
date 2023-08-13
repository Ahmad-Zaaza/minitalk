/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:05:50 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/14 00:26:19 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send_signal(int *bits, int pid) {
  int i;
  i = 0;
  while (i < 8) {
    if (bits[i] == 0) {
      kill(pid, SIGUSR1);
    } else {
      kill(pid, SIGUSR2);
    }
    usleep(200);
    i++;
  }
  free(bits);
}
