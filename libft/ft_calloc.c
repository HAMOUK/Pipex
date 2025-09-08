/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:16 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:33:57 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	temp = (unsigned char *)malloc(count * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
