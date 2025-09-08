/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:42:12 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:34:35 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //belek
#include <stdlib.h>
#include "libft.h"

int	count_size(long nb)
{
	int		count;
	long	num;

	num = nb;
	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	long	nbr;
	char	*dest;

	nbr = n;
	size = count_size(nbr);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	if (nbr == 0)
		dest[0] = '0';
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr = nbr * -1;
	}
	dest[size] = '\0';
	while (nbr > 0)
	{
		dest[size - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	return (dest);
}
/*int	main(void)
{
	ft_itoa(-283);
	return (0);
}*/
