/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:04:26 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:52:01 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexamin(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_hexamin(n / 16);
	ft_putchar_fd(base[n % 16], 1);
}

int	handle_hexamin(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	ft_hexamin(n);
	return (ft_hexalen(n));
}
