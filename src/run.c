/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:15:51 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:27:02 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_files(t_px *px, int *infd, int *outfd)
{
	*infd = open(px->infile, O_RDONLY);
	if (*infd == -1)
	{
		perror(px->infile);
		return (0);
	}
	*outfd = open(px->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (*outfd == -1)
	{
		close(*infd);
		perror(px->outfile);
		return (0);
	}
	return (1);
}

static int	create_pipe(int pipefd[2], int infd, int outfd)
{
	if (pipe(pipefd) == -1)
	{
		close(infd);
		close(outfd);
		perror("pipe");
		return (0);
	}
	return (1);
}

static void	cleanup_fds(int infd, int outfd, int pipefd[2])
{
	close(infd);
	close(outfd);
	close(pipefd[0]);
	close(pipefd[1]);
}

static int	fork_and_exec_cmd1(t_px *px, int pipefd[2], int infd, char **envp)
{
	pid_t	p1;

	p1 = fork();
	if (p1 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (p1 == 0)
		px_exec_cmd1(px, pipefd, infd, envp);
	return (p1);
}

int	px_run(t_px *px, char **envp)
{
	int		pipefd[2];
	int		infd;
	int		outfd;
	pid_t	p1;
	pid_t	p2;

	if (!open_files(px, &infd, &outfd))
		return (1);
	if (!create_pipe(pipefd, infd, outfd))
		return (1);
	p1 = fork_and_exec_cmd1(px, pipefd, infd, envp);
	if (p1 == -1)
	{
		cleanup_fds(infd, outfd, pipefd);
		return (1);
	}
	p2 = fork_and_exec_cmd2(px, pipefd, outfd, envp);
	if (p2 == -1)
	{
		cleanup_fds(infd, outfd, pipefd);
		waitpid(p1, NULL, 0);
		return (1);
	}
	cleanup_fds(infd, outfd, pipefd);
	return (wait_for_children(p1, p2));
}
