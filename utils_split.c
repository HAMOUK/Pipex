/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:15:38 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/03 17:38:49 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	skip_blanks(const char *s, int i)
{
	while (s[i] && is_white_space(s[i]))
		i++;
	return (i);
}

void	qstate_init(t_qstate *q)
{
	q->in_single = 0;
	q->in_double = 0;
}

void	qstate_toggle(t_qstate *q, char c)
{
	if (c == '\'' && !q->in_double)
		q->in_single = !q->in_single;
	else if (c == '"' && !q->in_single)
		q->in_double = !q->in_double;
}