/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:30:38 by rde-migu          #+#    #+#             */
/*   Updated: 2024/07/03 23:09:42 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	actual_char;
	static int				bit_index;

	actual_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (actual_char == END_TRANSMISSION)
			ft_printf("\n");
		else
			ft_printf("%c", actual_char);
		fflush(stdout);
		bit_index = 0;
		actual_char = 0;
	}
	else
		actual_char <<= 1;
}

int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}

/*void handle_signal(int signal)
{
    static unsigned char current_char;
    static int bit_index;

    current_char |= (signal == SIGUSR1);
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
}

int main(void)
{
    printf("PID del servidor: %d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        pause();
    return 0;
}*/


