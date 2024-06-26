/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:15:17 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/20 20:15:23 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*dest_cpy++ = *src_cpy++;
	}
	else
	{
		dest_cpy += n;
		src_cpy += n;
		while (n--)
			*--dest_cpy = *--src_cpy;
	}
	return (dest);
}
/*int main()
{
	int		str[] = {1,2,3,4,5,6,7,8,9,10};
	int		dst[10];
	int		i = 0;
	ft_memmove(dst, str, sizeof(int) * 10);
	while (i < 10)
	{
		printf("%d", dst[i]);
		i++;
	}
		return (0);
}*/
