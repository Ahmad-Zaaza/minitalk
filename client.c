/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:41:10 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 02:53:10 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str) {
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int *char_to_binary(int c) {
  int *bytes;
  int size;
  int letter;
  size = 8;
  bytes = calloc(size, sizeof(int));
  if (!bytes)
    return (NULL);
  letter = c;
  while (size > 0) {
    bytes[size - 1] = letter & 1;
    letter = letter >> 1;
    size--;
  }
  // int i = 0;
  // while (i < 8) {
  //   printf("%d", bytes[i]);
  //   i++;
  // }
  // printf("\n");
  return bytes;
}

int **message_to_binary(char *message) {
  int **bytes_arr;
  int message_len;
  int i;
  message_len = ft_strlen(message);
  bytes_arr = calloc(message_len, sizeof(int *));
  if (!bytes_arr)
    return (NULL);
  i = 0;
  while (message[i]) {
    bytes_arr[i] = char_to_binary(message[i]);
    i++;
  }
  return bytes_arr;
}

int main(int argc, char **argv) {
  int signal;
  int **message;
  pid_t pid;
  if (argc != 3) {
    printf("Error: Wrong number of arguments\n");
    exit(1);
  }

  message = message_to_binary(argv[2]);

  // signal = SIGUSR1;
  // pid = atoi(argv[1]);
  // kill(pid, signal);
  return (0);
}