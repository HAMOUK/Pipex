/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:52:00 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:26:37 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dest;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		dest = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int     main()
{
	const char      *s = "La Bonne Ball";
	unsigned int    start = 3;
	size_t len = 5;
	const char      *res;
	res = ft_substr(s, start, len);
	printf("%s\n", res);
	return (0);
}*/