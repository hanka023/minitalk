/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/13 16:10:27 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int pid()
{
pid_t server_pid = getpid();
return(server_pid);
}

void handler(int signum)
{
	static int bit;
	int num;
	char c;
	
	c = 0;
		if (signum == SIGUSR1)
		num = 0;
	else if (signum == SIGUSR2)
		num = 1;
	else 
		return ;

		
	c |= (num << bit); 
	bit ++;
	
	if (bit == 8)
	{
		ft_printf("%c\n");
		bit = 0;
	}
}

int main()
{
	ft_printf("Server PID: %d\n", pid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while(1)
		pause();

}