/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugolongin <hlongin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:09 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/15 15:25:07 by hugolongin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
