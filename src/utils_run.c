/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:23:43 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:26:27 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_and_exec_cmd2(t_px *px, int pipefd[2], int outfd, char **envp)
{
	pid_t	p2;

	p2 = fork();
	if (p2 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (p2 == 0)
		px_exec_cmd2(px, pipefd, outfd, envp);
	return (p2);
}

int	wait_for_children(pid_t p1, pid_t p2)
{
	int	status1;
	int	status2;

	waitpid(p1, &status1, 0);
	waitpid(p2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
