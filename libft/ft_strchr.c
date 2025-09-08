/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:10 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 15:51:54 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (0);
}

/*#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char *str = "Hello, world!";
	char c = 'o';
	char *res;

	res = ft_strchr(str, c);
	if (res)
		printf("'%c' trouvé à %ld : \"%s\"\n", c, res - str, res);
	else
		printf("'%c' non trouvé.\n", c);

	res = ft_strchr(str, 'x');
	if (!res)
		printf("'x' non trouvé (OK)\n");

	res = ft_strchr(str, '\0');
	printf("'\\0' trouvé à %ld\n", res - str);

	return (0);
}*/