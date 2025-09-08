/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:40 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:16:13 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (dstsize > 0)
	{
		if (i < dstsize)
			ft_memcpy(dst, src, i + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (i);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char buffer[10];
	const char *src = "Hello, world!";
	size_t copied;

	copied = ft_strlcpy(buffer, src, sizeof(buffer));
	printf("Copié      : \"%s\"\n", buffer);

	return (0);
}*/