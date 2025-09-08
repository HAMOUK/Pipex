/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:26 by hlongin           #+#    #+#             */
/*   Updated: 2025/04/22 13:48:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (c);
	else
		return (0);
}
/*#include <stdio.h>
int main (int argc, char **argv)
{
	int		res;

	if (argc == 2)
	{
		res = ft_isalnum(argv[1][0]);
		printf("res = %d\n", res);
	}
	else
		printf("Erreur");
	return 0;
}*/
