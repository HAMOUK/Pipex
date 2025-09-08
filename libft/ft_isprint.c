/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:42:01 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 14:34:28 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
		res = ft_isprint(argv[1][0]);
		printf("res = %d\n", res);
	}
	else
		printf("Error");
	return 0;
}*/
