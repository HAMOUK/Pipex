/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:49:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:28:04 by hlongin          ###   ########.fr       */
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
	if (!cmd || !cmd[0])
		return (NULL);
	if (has_slash(cmd))
		return (try_command_with_slash(cmd));
	if (!paths)
		return (NULL);
	return (search_command_in_paths(cmd, paths));
}

char	*join3(const char *a, const char *b, const char *c)
{
	int		total_len;
	int		i;
	char	*s;

	total_len = calculate_total_length(a, b, c);
	s = (char *)malloc(total_len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (a && *a)
		s[i++] = *a++;
	while (b && *b)
		s[i++] = *b++;
	while (c && *c)
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
