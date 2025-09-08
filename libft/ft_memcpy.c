/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:45 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 15:59:27 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tempdest;
	unsigned char		*tempsrc;
	size_t				i;

	i = 0;
	tempdest = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>  // juste pour comparaison si besoin
#include "libft.h"

int	main(void)
{
	const char	src[] = "Hello, world!";
	char		dst[50]; // buffer de destination suffisamment grand

	// Appel de ta fonction
	ft_memcpy(dst, src, strlen(src) + 1); // +1 pour inclure le '\0'

	printf("Source      : %s\n", src);
	printf("Destination : %s\n", dst);

	return (0);
}*/
/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("--- Test memcpy(NULL, NULL, 0) ---\n");

	void *r1 = ft_memcpy(NULL, NULL, 0);
	void *r2 = memcpy(NULL, NULL, 0);

	printf("ft_memcpy(NULL, NULL, 3) = %p\n", r1);
	printf("memcpy   (NULL, NULL, 3) = %p\n", r2);

	return 0;
}*/