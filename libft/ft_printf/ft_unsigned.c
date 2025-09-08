/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:17:46 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:59:24 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_put_unsigned(unsigned int un)
{
	if (un >= 10)
		ft_put_unsigned(un / 10);
	ft_putchar_fd((un % 10) + '0', 1);
}

int	ft_unsigned_len(unsigned int un)
{
	int	count;

	count = 1;
	while (un >= 10)
	{
		un = un / 10;
		count++;
	}
	return (count);
}

int	ft_unsigned(va_list *args)
{
	unsigned int	un;

	un = va_arg(*args, unsigned int);
	ft_put_unsigned(un);
	return (ft_unsigned_len(un));
}
