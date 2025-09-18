/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:13:48 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:28:44 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	setup_cmd_io(int infd, int outfd, int unused_pipe)
{
	if (x_dup2(infd, STDIN_FILENO) == -1)
		return (0);
	if (x_dup2(outfd, STDOUT_FILENO) == -1)
		return (0);
	close(unused_pipe);
	return (1);
}

char	*search_in_paths(const char *cmd, char **paths)
{
	char	*cand;
	int		i;

	i = 0;
	while (paths[i])
	{
		cand = build_candidate(paths[i], cmd);
		if (cand && access(cand, X_OK) == 0)
		{
			free_tab(paths);
			return (cand);
		}
		free(cand);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

char	*try_direct_path(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}
