/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:37 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:11:37 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	i = 0;
	while (src[i] && (len_dst + i) < (dstsize - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char buffer[20] = "Hello";
	const char *src = " world!";
	size_t size = sizeof(buffer);
	size_t result;

	result = ft_strlcat(buffer, src, size);
	printf("Résultat : \"%s\"\n", buffer);
	printf("Longueur totale : %zu\n", result);

	return (0);
}*/