/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:38:21 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:50:38 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
