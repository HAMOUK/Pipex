/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:17:27 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:52:37 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int nb)
{
	long	n;
	int		count;

	n = (long)nb;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	ft_int(va_list *args)
{
	int	nb;

	nb = va_arg(*args, int);
	ft_putnbr_fd(nb, 1);
	return (ft_intlen(nb));
}
