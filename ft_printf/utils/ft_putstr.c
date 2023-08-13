/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:21:54 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/13 23:10:17 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_putstr(char *str) {
  int i;

  if (!str) {
    ft_putstr("(null)");
    return (6);
  }
  i = 0;
  while (str[i])
    ft_putchar(str[i++]);
  return (i);
}
