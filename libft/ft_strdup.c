/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:42:15 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/22 15:18:18 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*s2;

	size = ft_strlen(s1);
	i = 0;
	s2 = (char *)malloc(sizeof(char) * size + 1);
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	char *res;

	if (argc == 2)
	{
		res = ft_strdup(argv[1]);
		printf("res = %s\n", res);
	}
	else
	{
		printf("error");
	}
	return 0;
}*/
