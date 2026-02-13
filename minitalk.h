/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/13 17:23:06 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include "./ft_printf/ft_printf.h"



/********	main	********/

int		main();

/********	server	********/

void	handler(int signum);
int		server();

/********	client	********/

pid_t	getpid(void);
int		kill(int pid, int sig);
void	send_char(int pid, char c);

/********	utils	********/

int		ft_atoi(const char *str);

#endif