/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:21:52 by hugolongin        #+#    #+#             */
/*   Updated: 2025/05/20 13:34:52 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_ptrlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr(n / 16);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_pointer(va_list *args)
{
	unsigned long	addr;
	void			*ptr;
	int				len;

	ptr = va_arg(*args, void *);
	addr = (unsigned long)ptr;
	len = 2;
	if (addr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		ft_put_ptr(addr);
		len += ft_ptrlen(addr);
	}
	return (len);
}
