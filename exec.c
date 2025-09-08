/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:40:51 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/08 12:10:56 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	x_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		return (-1);
	close(oldfd);
	return (0);
}

char	*px_resolve_path(const char *cmd, char **envp)
{
	char	**paths;
	char	*cand;
	int		i;

	if (!cmd || !*cmd)
		return (NULL);
	if (has_slash(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = px_get_paths(envp);
	if (!paths)
		return (NULL);
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

void	px_exec_cmd1(t_px *px, int pipefd[2], int infd, char **envp)
{
	char	*path;

	if (x_dup2(infd, STDIN_FILENO) == -1)
		exit(1);
	if (x_dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit(1);
	close(pipefd[0]);
	path = px_resolve_path(px->cmd1_argv[0], envp);
	if (!path)
	{
		perror(px->cmd1_argv[0]);
		exit(127);
	}
	execve(path, px->cmd1_argv, envp);
	perror(path);
	free(path);
	exit(126);
}

void	px_exec_cmd2(t_px *px, int pipefd[2], int outfd, char **envp)
{
	char	*path;

	if (x_dup2(pipefd[0], STDIN_FILENO) == -1)
		exit(1);
	if (x_dup2(outfd, STDOUT_FILENO) == -1)
		exit(1);
	close(pipefd[1]);
	path = px_resolve_path(px->cmd2_argv[0], envp);
	if (!path)
	{
		perror(px->cmd2_argv[0]);
		exit(127);
	}
	execve(path, px->cmd2_argv, envp);
	perror(path);
	free(path);
	exit(126);
}
