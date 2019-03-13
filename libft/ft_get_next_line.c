/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:48:38 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/08 12:25:05 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_b_add(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		if (s[i + 1] == '\0')
			return (i + 1);
		i++;
	}
	return (0);
}

t_stor			*get_struct(int fd, t_stor **data)
{
	t_stor	*iter;

	iter = *data;
	while (iter)
	{
		if (iter->fd == fd)
			return (iter);
		iter = iter->next;
	}
	iter = (t_stor*)malloc(sizeof(*iter));
	iter->fd = fd;
	iter->buf = NULL;
	iter->next = *data;
	*data = iter;
	return (iter);
}

char			*add_str(char *stock, char *buf, int b)
{
	char	*out;

	out = ft_strnew((size_t)(ft_strlen(stock) + b));
	if (!out)
	{
		free(stock);
		return (NULL);
	}
	out = ft_strcpy(out, (const char *)stock);
	out = ft_strncat(out, (const char *)buf, (size_t)b);
	free(stock);
	return (out);
}

int				gnl_aux(char **line, t_stor **n_in)
{
	char			*tmp;
	t_stor			*n;

	*line = ft_strnew(0);
	n = *n_in;
	if (n->buf)
	{
		n->b_add = count_b_add(n->buf);
		*line = add_str(*line, n->buf, n->b_add);
		if ((size_t)n->b_add < ft_strlen(n->buf))
		{
			tmp = ft_strdup(&(n->buf[n->b_add + 1]));
			free(n->buf);
			n->buf = tmp;
			return (1);
		}
		else
		{
			free(n->buf);
			n->buf = NULL;
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_stor	*data;
	t_stor			*n;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	n = get_struct((int)fd, &data);
	if (gnl_aux(line, &n))
		return (1);
	while ((n->b_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n->b_read] = '\0';
		n->b_add = count_b_add(buf);
		*line = add_str(*line, buf, n->b_add);
		if (n->b_add < n->b_read)
		{
			n->buf = ft_strdup(&(buf[n->b_add + 1]));
			return (1);
		}
	}
	if (ft_strlen(*line))
		return (1);
	return (0);
}
