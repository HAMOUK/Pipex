/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:43:35 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 13:50:22 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char *s1 = "Hello, world!";
	const char *s2 = "Hello, worle!";
	size_t		n = 13;

	int	result = ft_memcmp(s1, s2, n);

	if (result == 0)
		printf("Les %zu premiers octets sont identiques.\n", n);
	else if (result < 0)
		printf("s1 est inférieure à s2 (différence : %d).\n", result);
	else
		printf("s1 est supérieure à s2 (différence : %d).\n", result);

	return (0);
}*/
