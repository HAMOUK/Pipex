/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:04:15 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 12:07:36 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_format_dispatch(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_char(args));
	if (specifier == 's')
		return (ft_string(args));
	if (specifier == 'd' || specifier == 'i')
		return (ft_int(args));
	if (specifier == 'u')
		return (ft_unsigned(args));
	if (specifier == 'x')
		return (handle_hexamin(args));
	if (specifier == 'X')
		return (handle_hexamaj(args));
	if (specifier == 'p')
		return (ft_pointer(args));
	return (-1);
}

int	ft_format_handler(const char *format, int i, va_list *args)
{
	int	count;
	int	res;

	count = 0;
	if (format[i] == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else
	{
		res = ft_format_dispatch(format[i], args);
		if (res >= 0)
			count += res;
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_format_handler(format, ++i, &args);
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include "printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	//int		nb = INT_MIN;
	//char	c = 'A';
	//char	*str = "Hello, 42!";
	//unsigned int u = 424242;
	//unsigned int hex = 0x1A3F;
	//void	*ptr = 0;

	ft_printf("---- FT_PRINTF TESTS ----\n");

	//ft_printf("1. Char: [%c]\n", c);
	//ft_printf("2. String: [%s]\n", str);
	//ft_printf("3. Decimal (int): [%d]\n", nb);
	ft_printf(" %d ", INT_MIN);
	//ft_printf("4. Decimal (int): [%i]\n", nb);
	//ft_printf("5. Unsigned: [%u]\n", u);
	//ft_printf("6. Hexa lowercase: [%x]\n", hex);
	//ft_printf("7. Hexa uppercase: [%X]\n", hex);
	//ft_printf("8. Pointer: [%p]\n", ptr);
	//ft_printf(" %p %p ", 0, 0);
	//ft_printf("9. Percent sign: [%%]\n");

	//ft_printf("--------------------------\n");

	// Compare with printf
	//printf("\n---- SYSTEM PRINTF ----\n");
	//printf("1. Char: [%c]\n", c);
	//printf("2. String: [%s]\n", str);
	//printf("3. Decimal (int): [%d]\n", nb);
	printf(" %d\n ", INT_MIN);
	//printf("4. Decimal (int): [%i]\n", nb);
	//printf("5. Unsigned: [%u]\n", u);
	//printf("6. Hexa lowercase: [%x]\n", hex);
	//printf("7. Hexa uppercase: [%X]\n", hex);
	//printf("8. Pointer: [%p]\n", ptr);
	//printf(" %p %p ", 0, 0);
	//printf("9. Percent sign: [%%]\n");

	return (0);
}*/