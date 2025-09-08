/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:12:36 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/08 14:13:02 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd_simple(const char *line)
{
	int		count;
	char	**argv;

	if (!line)
		return (NULL);
	count = count_tokens(line);
	if (count < 0)
		return (NULL);
	argv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	if (!fill_argv(line, argv))
	{
		free_tab(argv);
		return (NULL);
	}
	return (argv);
}

void	free_tab(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
void	free_partial_tab(char **argv, int count)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (i < count && argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
