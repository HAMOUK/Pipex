/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:38:58 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/03 18:28:53 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	buf_init(t_buf *b)
{
	if (!b)
		return (0);
	b->len = 0;
	b->cap = 16;
	b->data = (char *)malloc(sizeof(char) * b->cap);
	if (!b->data)
	{
		b->cap = 0;
		return (0);
	}
	return (1);
}

static int	buf_grow(t_buf *b)
{
	char	*new_data;
	int		new_cap;
	int		i;

	if (!b)
		return (0);
	if (b->cap > 0)
		new_cap = b->cap * 2;
	else
		new_cap = 16;
	new_data = (char *)malloc(sizeof(char) * new_cap);
	if (!new_data)
		return (0);
	i = 0;
	while (i < b->len)
	{
		new_data[i] = b->data[i];
		i++;
	}
	free(b->data);
	b->data = new_data;
	b->cap = new_cap;
	return (1);
}

int	buf_push(t_buf *b, char c)
{
	if (!b)
		return (0);
	if (b->cap == 0 || b->len >= b->cap)
	{
		if (!buf_grow(b))
			return (0);
	}
	b->data[b->len] = c;
	b->len++;
	return (1);
}

char	*buf_to_cstr(t_buf *b)
{
	char	*dst;
	int		i;

	if (!b)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (b->len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < b->len)
	{
		dst[i] = b->data[i];
		i++;
	}
	dst[b->len] = '\0';
	return (dst);
}

void	buf_free(t_buf *b)
{
	if (!b)
		return ;
	if (b->data)
		free(b->data);
	b->data = NULL;
	b->len = 0;
	b->cap = 0;
}
