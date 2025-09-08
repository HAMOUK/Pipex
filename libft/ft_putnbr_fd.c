/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:03 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:35:11 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

/*#include <unistd.h>
#include "libft.h" // ou déclare ft_putnbr_fd si besoin

int	main(void)
{
	// Test de plusieurs cas
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-12345, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);

	return (0);
}*/
