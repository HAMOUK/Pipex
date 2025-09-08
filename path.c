/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:49:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/08 12:26:10 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**px_get_paths(char **envp)
{
	const char	*val;
	int			count;

	val = px_find_path_value(envp);
	if (!val)
		return (NULL);
	count = px_count_segments(val);
	if (count <= 0)
		return (NULL);
	return (px_fill_segments(val, count));
}

char	*px_find_cmd_path(const char *cmd, char **paths)
{
	char	*cand;
	int		i;

	if (!cmd || !cmd[0])
		return (NULL);
	if (has_slash(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (!paths)
		return (NULL);
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

char	*join3(const char *a, const char *b, const char *c)
{
	int		la;
	int		lb;
	int		lc;
	int		i;
	char	*s;

	if (!a)
		a = "";
	if (!b)
		b = "";
	if (!c)
		c = "";
	la = ft_strlen(a);
	lb = ft_strlen(b);
	lc = ft_strlen(c);
	s = (char *)malloc(la + lb + lc + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (*a)
		s[i++] = *a++;
	while (*b)
		s[i++] = *b++;
	while (*c)
		s[i++] = *c++;
	s[i] = '\0';
	return (s);
}

char	*build_candidate(const char *dir, const char *cmd)
{
	if (dir && dir[0] == '.' && dir[1] == '\0')
		return (join3("./", "", cmd));
	return (join3(dir, "/", cmd));
}