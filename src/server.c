/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:30:38 by rde-migu          #+#    #+#             */
/*   Updated: 2024/07/01 19:38:26 by rde-migu         ###   ########.fr       */
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
