/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:15:28 by rde-migu          #+#    #+#             */
/*   Updated: 2024/07/03 23:52:23 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler_confirmed(int sig)
{
    (void)sig;
	bit_received = 1;
}

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!bit_received)
			usleep(50);
		bit_received = 0;
	}
}

int	main(int argc, char *argv[])
{
	__pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, handler_confirmed);
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
