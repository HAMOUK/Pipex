/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:40:51 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:16:39 by hlongin          ###   ########.fr       */
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

	if (!cmd || !*cmd)
		return (NULL);
	if (has_slash(cmd))
		return (try_direct_path(cmd));
	paths = px_get_paths(envp);
	if (!paths)
		return (NULL);
	return (search_in_paths(cmd, paths));
}

void	px_exec_cmd1(t_px *px, int pipefd[2], int infd, char **envp)
{
	char	*path;

	if (!setup_cmd_io(infd, pipefd[1], pipefd[0]))
		exit(1);
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

	if (!setup_cmd_io(pipefd[0], outfd, pipefd[1]))
		exit(1);
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
