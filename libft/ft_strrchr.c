/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:53 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 15:47:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*stock;
	char	cc;
	int		i;

	i = 0;
	cc = (char)c;
	stock = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			stock = (char *)&s[i];
		i++;
	}
	if (cc == s[i])
		stock = (char *)&s[i];
	return (stock);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char *str = "bonjour, jour bon";
	char c = 'j';

	char *res = ft_strrchr(str, c);

	if (res)
		printf("Dernier '%c' trouvé à : \"%s\"\n", c, res);
	else
		printf("Caractère '%c' non trouvé.\n", c);

	// Test avec '\0'
	printf("Avec '\\0' : %p\n", (void *)ft_strrchr(str, '\0'));

	return (0);
}*/