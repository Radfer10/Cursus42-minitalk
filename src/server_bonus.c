/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:15:34 by rde-migu          #+#    #+#             */
/*   Updated: 2024/07/03 23:52:45 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

#define END_TRANSMISSION '\0'

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)context;

    static unsigned char current_char;
    static int bit_index;
    __pid_t client_pid;

    client_pid = info->si_pid;

    current_char |= (sig == SIGUSR1);
    bit_index++;
    if (bit_index == 8)
    {
        if (current_char == END_TRANSMISSION)
            printf("\n");
        else
            printf("%c", current_char);
        fflush(stdout);
        bit_index = 0;
        current_char = 0;
    }
    else
        current_char <<= 1;
    kill(client_pid, SIGUSR1);
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
