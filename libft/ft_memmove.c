/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:52 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 13:53:14 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp_dst;
	char		*temp_src;
	size_t		i;

	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	}
	else
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>  // pour comparaison avec memmove si besoin
#include "libft.h"

int	main(void)
{
	char str[100] = "1234567890";

	// Affichage avant
	printf("Avant memmove : %s\n", str);

	// On copie une zone qui chevauche : décaler vers la droite
	ft_memmove(str + 4, str, 6); // copie "123456" à partir de str+4

	// Affichage après
	printf("Après memmove : %s\n", str);

	return (0);
}*/
