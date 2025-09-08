/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:28:31 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/04 12:51:20 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	count_tokens(const char *s)
{
	int			i;
	int			count;
	t_qstate 	q;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		i = skip_blanks(s, i);
		if (!s[i])
			break;
		count++;
		qstate_init(&q);
		while (s[i] && (q.in_single || q.in_double || !is_white_space(s[i])))
		{
			if (s[i] == '\'' && !q.in_double)
				qstate_toggle(&q, s[i]);
			else if (s[i] == '\"' && !q.in_single)
				qstate_toggle(&q, s[i]);
			else if (s[i] == '\\' && !q.in_single)
			{
				if (!s[i + 1])
					return (-1);
				i++;
			}
			i++;
		}
		if (q.in_double || q.in_single)
			return (-1);
	}
	return (count);
}

int	fill_argv(const char *s, char **argv)
{
	int		i;
	int		k;
	t_qstate	q;
	t_buf		buf;

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
		qstate_init(&q);
		if (!buf_init(&buf))
			return (0);
		while (s[i] && (q.in_single || q.in_double || !is_white_space(s[i])))
		{
			if (s[i] == '\'' && !q.in_double)
				qstate_toggle(&q, s[i]);
			else if (s[i] == '"' && !q.in_single)
				qstate_toggle(&q, s[i]);
			else if (s[i] == '\\' && !q.in_single)
			{
				if (!s[i + 1] || !handle_backslash(s, &i, &q, &buf))
					return (buf_free(&buf), 0);
			}
			else if (!buf_push(&buf, s[i]))
				return (buf_free(&buf), 0);
			i++;
		}
		if (q.in_single || q.in_double)
			return (buf_free(&buf), 0);
		argv[k] = buf_to_cstr(&buf);
		buf_free(&buf);
		if (!argv[k])
			return (0);
		k++;
		argv[k] = NULL;
	}
	argv[k] = NULL;
	return (1);
}
