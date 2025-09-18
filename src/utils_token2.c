/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:29:17 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:46:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fill_argv(const char *s, char **argv)
{
	int	i;
	int	k;

	if (!s || !argv)
		return (0);
	i = 0;
	k = 0;
	argv[0] = NULL;
	while (s[i])
	{
		i = skip_blanks(s, i);
		if (!s[i])
			break ;
		if (!extract_token(s, &i, &argv[k]))
		{
			free_partial_tab(argv, k);
			return (0);
		}
		k++;
		argv[k] = NULL;
	}
	return (1);
}

int	extract_token(const char *s, int *i, char **token)
{
	t_qstate	q;
	t_buf		buf;

	qstate_init(&q);
	if (!buf_init(&buf))
		return (0);
	while (s[*i] && (q.in_single || q.in_double || !is_white_space(s[*i])))
	{
		if (!handle_token_char(s, i, &q, &buf))
		{
			buf_free(&buf);
			return (0);
		}
		(*i)++;
	}
	if (q.in_single || q.in_double)
	{
		buf_free(&buf);
		return (0);
	}
	*token = buf_to_cstr(&buf);
	buf_free(&buf);
	return (*token != NULL);
}

int	handle_token_char(const char *s, int *i, t_qstate *q, t_buf *buf)
{
	if (s[*i] == '\'' && !q->in_double)
		qstate_toggle(q, s[*i]);
	else if (s[*i] == '"' && !q->in_single)
		qstate_toggle(q, s[*i]);
	else if (s[*i] == '\\' && !q->in_single)
	{
		if (!s[*i + 1] || !handle_backslash(s, i, q, buf))
			return (0);
	}
	else if (!buf_push(buf, s[*i]))
		return (0);
	return (1);
}

int	handle_backslash(const char *s, int *i, t_qstate *q, t_buf *b)
{
	(void)q;
	if (!s || !i || !b)
		return (0);
	if (s[*i + 1] == '\0')
		return (0);
	if (!buf_push(b, s[*i + 1]))
		return (0);
	*i = *i + 1;
	return (1);
}
