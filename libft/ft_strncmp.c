/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:48 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 15:17:46 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char *a = "Hello";
	const char *b = "Helium";
	size_t n = 3;

	int res = ft_strncmp(a, b, n);
	printf("Résultat (n = %zu) : %d\n", n, res);

	n = 5;
	res = ft_strncmp(a, b, n);
	printf("Résultat (n = %zu) : %d\n", n, res);

	return (0);
}*/