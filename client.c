/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/13 18:02:00 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
int	bit;

bit = 0;
while (bit <= 7)
{
	if ((c >> bit) & 1)
	{
		kill(pid, SIGUSR2);
		usleep (500);
	}
	else 
	{
		kill(pid, SIGUSR1);
		usleep (500);
	}
	++bit;
}
return ;
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	c;
	int		pid;
	
	if(argc < 3)
		return(0);
	c = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_char(pid, *str);
		++str;
	}
	return (0);
}
