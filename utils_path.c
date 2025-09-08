/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:01:16 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/04 14:51:57 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const char 	*px_find_path_value(char **envp)
{
	int		i;
	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
			if (!ft_strncmp(envp[i], "PATH=", 5))
				return (envp[i] + 5);
		i++;
	}
	return (NULL); 
}

int		px_count_segments(const char *s)
{
	int		count;
	int		i;

	if (!s)
		return (0);
	if (s[0] == '\0')
		return (1);
	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == ':')
			count++;
		i++;
	}
	return (count);
}
char	**px_fill_segments(const char *s, int count)
{
	char	**tab;
	int		i;
	int		start;
	int		len;

	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	start = 0;
	while (i < count)
	{
		len = 0;
		while (s[start + len] && s[start + len] != ':')
			len++;
		if (len == 0)
			tab[i] = ft_strdup(".");
		else
			tab[i] = ft_substr(s, start, len);
		if (!tab[i])
		{
			free_tab(tab);
			return (NULL);
		} 
		start += len;
		if (s[start] == ':')
			start++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	has_slash(const char *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}