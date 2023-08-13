/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:41:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/14 00:44:46 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_numeric(const char *str) {
  if (!*str)
    return 0;
  if (*str == '+')
    str++;
  while (*str) {
    if (!is_digit(*str))
      return 0;
    str++;
  }
  return (1);
}

 int ft_atoi(const char *str) {
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