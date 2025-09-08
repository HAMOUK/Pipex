/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugolongin <hlongin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:34 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/15 15:27:13 by hugolongin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		len_tot;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len_tot) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int     main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_strjoin(argv[1], argv[2]);
	}
	else
		printf("Error");
	return (0);
}*/