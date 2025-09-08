/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:00:14 by hugolongin        #+#    #+#             */
/*   Updated: 2025/04/23 11:47:44 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_string(va_list *args);
int		ft_char(va_list *args);
int		handle_hexamaj(va_list *args);
int		handle_hexamin(va_list *args);
int		ft_int(va_list *args);
int		ft_pointer(va_list *args);
int		ft_unsigned(va_list *args);
int		ft_hexalen(unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
