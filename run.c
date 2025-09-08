/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:15:51 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/08 14:20:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_run(t_px *px, char **envp)
{
	int		pipefd[2];
	int		infd;
	int		outfd;
	pid_t	p1;
	pid_t	p2;
	int		status1;
	int		status2;

	infd = open(px->infile, O_RDONLY);
	if (infd == -1)
	{
		perror(px->infile);
		return (1);
	}
	outfd = open(px->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (outfd == -1)
	{
		close(infd);
		perror(px->outfile);
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		close(infd);
		close(outfd);
		perror("pipe");
		return (1);
	}
	p1 = fork();
	if (p1 == -1)
	{
		close(infd);
		close(outfd);
		close(pipefd[0]);
		close(pipefd[1]);
		perror("fork");
		return (1);
	}
	if (p1 == 0)
		px_exec_cmd1(px, pipefd, infd, envp);
	p2 = fork();
	if (p2 == -1)
	{
		close(infd);
		close(outfd);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(p1, NULL, 0);
		perror("fork");
		return (1);
	}
	if (p2 == 0)
		px_exec_cmd2(px, pipefd, outfd, envp);
	close(infd);
	close(outfd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(p1, &status1, 0);
	waitpid(p2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
