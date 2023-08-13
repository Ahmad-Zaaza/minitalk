/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:41:10 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 23:15:39 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int ft_atoi(const char *str) {
  long int result;
  long int old_result;
  int i;
  int sign;

  result = 0;
  i = 0;
  sign = 1;
  while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  if (str[i] == 45)
    sign = -1;
  i += (str[i] == '-' || str[i] == '+');
  while (str[i] >= '0' && str[i] <= '9') {
    old_result = result;
    result = (result * 10) + (str[i++] - 48);
    if (old_result > result) {
      if (sign < 0)
        return (0);
      return (-1);
    }
  }
  return (result * sign);
}

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
    ft_printf("Error: Wrong number of arguments\n");
    exit(1);
  }
  pid = ft_atoi(argv[1]);
  i = 0;
  while (argv[2][i]) {
    transform_and_send(argv[2][i], pid);
    i++;
  };

  return (0);
}
