/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/12 18:16:42 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


pid_t getpid(void);

int kill(int pid, int sig)
{
	
}


char send_char(int pid, char c)
{

	
ft_printf("Server PID: %d\n", pid);
	
	
}


int main(int argc, char *argv[])
{
	char *str;
	char c;
	int pid;
	
	if(argc < 3)
		return(0);
	c = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		*str = send_char(pid, c);
		++str;
	}
	return (0);
}