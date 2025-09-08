/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:20:20 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:45:55 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexamaj(unsigned int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_hexamaj(nbr / 16);
	ft_putchar_fd(base[nbr % 16], 1);
}

int	handle_hexamaj(va_list *args)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	ft_hexamaj(nbr);
	return (ft_hexalen(nbr));
}
