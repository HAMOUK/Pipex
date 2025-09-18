/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:17:58 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:22:49 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	calculate_total_length(const char *a, const char *b, const char *c)
{
	int	la;
	int	lb;
	int	lc;

	if (!a)
		a = "";
	if (!b)
		b = "";
	if (!c)
		c = "";
	la = ft_strlen(a);
	lb = ft_strlen(b);
	lc = ft_strlen(c);
	return (la + lb + lc);
}

char	*search_command_in_paths(const char *cmd, char **paths)
{
	char	*cand;
	int		i;

	i = 0;
	while (paths[i])
	{
		cand = build_candidate(paths[i], cmd);
		if (!cand)
			return (NULL);
		if (access(cand, X_OK) == 0)
			return (cand);
		free(cand);
		i++;
	}
	return (NULL);
}

char	*try_command_with_slash(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*create_segment(const char *s, int start, int len)
{
	if (len == 0)
		return (ft_strdup("."));
	else
		return (ft_substr(s, start, len));
}

int	fill_single_segment(const char *s, char **tab, int i, int *start)
{
	int	len;

	len = 0;
	while (s[*start + len] && s[*start + len] != ':')
		len++;
	tab[i] = create_segment(s, *start, len);
	if (!tab[i])
	{
		free_tab(tab);
		return (0);
	}
	*start += len;
	if (s[*start] == ':')
		(*start)++;
	return (1);
}
