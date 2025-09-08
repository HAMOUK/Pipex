/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 13:58:01 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char buffer[20];

	// Remplir le buffer avec des 'X'
	ft_memset(buffer, 'X', sizeof(buffer) - 1);
	buffer[19] = '\0'; // null-terminate pour l'affichage

	printf("Buffer rempli : %s\n", buffer);

	return (0);
}*/