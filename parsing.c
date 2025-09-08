/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:29:50 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/04 14:46:21 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		pars_args(int	argc, char **argv, t_px *px)
{
	if (argc != 5)
	{
		write(2, "error\n", 6);
		return(1);
	}
	px->infile = argv[1];
	px->cmd1_line = argv[2];
	px->cmd2_line = argv[3];
	px->outfile = argv[4];
	return (0);
}

int build_commands(t_px *px, char **envp)
{
	(void)envp;
	px->cmd1_argv = split_cmd_simple(px->cmd1_line);
	if (!px->cmd1_argv || !px->cmd1_argv[0])
	{	
		if (px->cmd1_argv)
			free_tab(px->cmd1_argv);
        return error("empty first command");
	}
	px->cmd2_argv = split_cmd_simple(px->cmd2_line);
    if (!px->cmd2_argv || !px->cmd2_argv[0])
	{
		free_tab(px->cmd1_argv);
		if (px->cmd2_argv)
			free_tab(px->cmd2_argv);
        return error("empty second command");
	}
	return (0);
}
