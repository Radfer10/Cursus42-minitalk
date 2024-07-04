/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:57:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/07/05 00:35:02 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_kill(__pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Error\n");
		exit(0);
	}
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
		if ((temp_char) & 1)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	__pid_t		pid_server;
	const char	*menssage;
	int			i;

	if (argc != 3)
	{
		ft_printf("Introducir Argumentos: %s <pid> <menssage>\n", argv[0]);
		exit(0);
	}
	pid_server = ft_atoi(argv[1]);
	menssage = argv[2];
	i = 0;
	while (menssage[i])
		send_signal(pid_server, menssage[i++]);
	send_signal(pid_server, '\0');
	return (0);
}
