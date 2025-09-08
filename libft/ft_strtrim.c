/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:24:51 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_letter(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupc(const char *start, const char *end)
{
	int		size;
	int		i;
	char	*dest;

	i = 0;
	size = end - start;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = *start;
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int			i;
	int			end_index;
	const char	*start;
	const char	*end;
	char		*dest;

	i = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[i] && check_letter(s1[i], set))
		i++;
	start = &s1[i];
	if (i > end_index)
		return (ft_strdupc("", ""));
	while (end_index >= 0 && check_letter(s1[end_index], set))
	{
		end_index--;
	}
	end = &s1[end_index + 1];
	dest = ft_strdupc(start, end);
	return (dest);
}
/*#include <stdio.h>
int	main(void)
{
	char    *res;

	res = ft_strtrim("abbaaaabbMy name is Hugoaaabbabba", "ab");
	printf("%s\n", res);
	return (0);
}*/