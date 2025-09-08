/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:55 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:34:25 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
/*#include <stdio.h>
int main(int argc, char **argv)
{
	int	res;
	if (argc == 2)
	{
		res = ft_isdigit(argv[1][0]);
		printf("res = %d\n", res);
	}
	else
		printf("Error");
	return 0;
}*/
