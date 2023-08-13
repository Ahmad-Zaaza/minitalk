/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:41:10 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 15:20:44 by azaaza           ###   ########.fr       */
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
    usleep(500);
    i++;
  }
  free(bits);
}

void *transform_and_send(int c, int pid) {
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
  send_signal(bits, pid);
  // int i = 0;
  // while (i < 8) {
  //   printf("%d", bits[i]);
  //   i++;
  // }
  // printf("\n");
  return bits;
}

// int **message_to_binary(char *message) {
//   int **bytes;
//   int message_len;
//   int i;
//   message_len = ft_strlen(message);
//   bytes = calloc(message_len, sizeof(int *));
//   if (!bytes)
//     return (NULL);
//   i = 0;
//   while (message[i]) {
//     bytes[i] = char_to_binary(message[i]);
//     i++;
//   }
//   return bytes;
// }

int main(int argc, char **argv) {
  int signal;
  int **message;
  pid_t pid;
  int i;

  if (argc != 3) {
    printf("Error: Wrong number of arguments\n");
    exit(1);
  }
  pid = atoi(argv[1]);
  i = 0;
  while (argv[2][i]) {
    transform_and_send(argv[2][i], pid);
    i++;
  };

  // signal = SIGUSR1;
  // kill(pid, signal);
  return (0);
}
