/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:28:31 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:39:19 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	process_token_char(const char *s, int *i, t_qstate *q)
{
	if (s[*i] == '\'' && !q->in_double)
		qstate_toggle(q, s[*i]);
	else if (s[*i] == '\"' && !q->in_single)
		qstate_toggle(q, s[*i]);
	else if (s[*i] == '\\' && !q->in_single)
	{
		if (!s[*i + 1])
			return (-1);
		(*i)++;
	}
	return (0);
}

static int	count_single_token(const char *s, int *i)
{
	t_qstate	q;
	int			result;

	qstate_init(&q);
	while (s[*i] && (q.in_single || q.in_double || !is_white_space(s[*i])))
	{
		result = process_token_char(s, i, &q);
		if (result == -1)
			return (-1);
		(*i)++;
	}
	if (q.in_double || q.in_single)
		return (-1);
	return (1);
}

int	count_tokens(const char *s)
{
	int	i;
	int	count;
	int	result;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		i = skip_blanks(s, i);
		if (!s[i])
			break ;
		count++;
		result = count_single_token(s, &i);
		if (result == -1)
			return (-1);
	}
	return (count);
}
