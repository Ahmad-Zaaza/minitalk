/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:05:50 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 15:17:30 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void signal_handler(int sig) {

  if (sig == SIGUSR1) {
    printf("SIGUSR1 received %d,...\n", sig);
  }
  if (sig == SIGUSR2) {
    printf("SIGUSR2 received %d,...\n", sig);
  }
}