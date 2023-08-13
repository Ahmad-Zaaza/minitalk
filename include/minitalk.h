/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:02:06 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/14 00:44:44 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

#define MINITALK_H

#include "../ft_printf/include/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void send_signal(int *bits, int pid);
int is_numeric(const char *str);
int ft_atoi(const char *str);

#endif