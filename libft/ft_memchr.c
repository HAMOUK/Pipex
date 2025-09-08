/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:43:28 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 13:50:04 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	str[] = "Hello, world!";
	int			c = 'w'; // caractère à chercher
	size_t		n = 10;  // nombre d’octets à examiner

	char *res = (char *)ft_memchr(str, c, n);

	if (res)
		printf("Trouvé '%c' à la position %ld\n", c, res - str);
	else
		printf("Caractère non trouve);

	return (0);
}*/