/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/02/13 16:02:36 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


char send_char(int pid, char c)
{
 int bit;

 bit = 0;
 while (bit < 8)
 {
	if ((c >> bit) & 1)
		kill(pid, SIGUSR2);
	else 
		kill(pid, SIGUSR1);
	++bit;
 }
return(0);
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