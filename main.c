/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:15:40 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/08 14:02:51 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_px px;
	int status;

	if (pars_args(argc, argv, &px))
		return (EXIT_FAILURE);
	if (build_commands(&px, envp))
		return (EXIT_FAILURE);
	status = px_run(&px, envp);
	free_tab(px.cmd1_argv);
	free_tab(px.cmd2_argv);
	return (status);
}