/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:41:10 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/14 01:30:38 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void *transform_and_send(int c, int pid) {
  int *bits;
  int size;
  int letter;

  size = 8;
  bits = calloc(size, sizeof(int));
  if (!bits)
    return (NULL);
  letter = c;
  while (size > 0) {
    bits[size - 1] = letter & 1;
    letter = letter >> 1;
    size--;
  }
  int i = 0;
  while (i < 8) {
    ft_printf("%d", bits[i]);
    i++;
  }
  ft_printf("\n");
  send_signal(bits, pid);
  return bits;
}

int main(int argc, char **argv) {
  pid_t pid;
  int i;

  if (argc != 3) {
    ft_printf("Error: Wrong number of arguments\n");
    exit(1);
  }
  if (!is_numeric(argv[1])) {
    ft_printf("🚨 Error: Invalid server PID\n");
    exit(1);
  }
  pid = ft_atoi(argv[1]);
  i = 0;
  while (argv[2][i]) {
    transform_and_send(argv[2][i], pid);
    i++;
  };
  transform_and_send('\n', pid);
  transform_and_send('\0', pid);

  return (0);
}
