/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:07 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 14:46:22 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_tab(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (word);
}

char	*ft_strdupcustom(const char *start, const char *end)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = end - start;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = *start;
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	skip_and_set(const char **s, int *i, const char **start, char c)
{
	while ((*s)[*i] == c)
		(*i)++;
	*start = &(*s)[*i];
	while ((*s)[*i] && (*s)[*i] != c)
		(*i)++;
}

char	**ft_split(const char *s, char c)
{
	int				word;
	int				i;
	int				ligne;
	const char		*start;
	char			**tab;

	i = 0;
	ligne = 0;
	word = count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	while (ligne < word)
	{
		skip_and_set(&s, &i, &start, c);
		tab[ligne] = ft_strdupcustom(start, &s[i]);
		if (!tab[ligne])
		{
			free_tab(tab, ligne);
			return (NULL);
		}
		ligne++;
	}
	tab[ligne] = NULL;
	return (tab);
}
