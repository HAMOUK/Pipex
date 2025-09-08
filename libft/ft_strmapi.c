/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:45 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:18:02 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*dest;

	i = 0;
	size = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	while (i < size)
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	const char *s = "hello world";
	char *res = ft_strmapi(s, to_upper_even);

	if (res)
	{
		printf("Original : %s\n", s);
		printf("Modifié  : %s\n", res);
		free(res);
	}
	else
		printf("Allocation échouée.\n");

	return (0);
}*/