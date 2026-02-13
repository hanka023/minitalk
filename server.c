/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/13 18:25:30 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	handler(int signum)
{
	static int	bit;
	int			num;
	static char	c;
	
	num = 0;
	if (signum == SIGUSR1)
		num = 0;
	else if (signum == SIGUSR2)
		num = 1;
	else 
		return ;

	c |= (num << bit); 
	bit++;
	
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	return ;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	
	ft_printf("Server PID: %d\n", getpid());

	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while (1)	
		pause ();
		
	return (0);
}