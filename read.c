/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:08:34 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/19 14:19:38 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_words(char **splitted_words)
{
	int i;

	if (!splitted_words)
		return (0);
	i = 0;
	while (splitted_words[i])
		i++;
	return (i);
}

int		count_y(t_fdf *st)
{
	int		fd;
	int		y;
	char	*l;

	y = 0;
	if ((fd = open(st->n, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &l) > 0)
		y++;
	if (y == 0)
		return (0);
	st->y = y;
	close(fd);
	return (1);
}

int		fill_lineint(char **w, int *a)
{
	int	i;

	i = 0;
	while (w[i])
	{
		if (!ft_atoi_fdf(w[i], &(a[i])))
			return (0);
		i++;
	}
	return (1);
}

int		fillall_validate(t_fdf *st)
{
	int		fd;
	char	*l;
	char	**w;
	int		i;

	if (((fd = open(st->n, O_RDONLY)) == -1) || !(count_y(st)))
		return (0);
	i = 0;
	st->x = 0;
	MALLCHECK((st->map = (int **)malloc(sizeof(int *) * st->y)));
	while (get_next_line(fd, &l) > 0 && i < st->y)
	{
		w = ft_strsplit(l, ' ');
		if (i == 0)
			st->x = count_words(w);
		else if (st->x != count_words(w) || st->x == 0)
			return (0);
		MALLCHECK((st->map[i] = (int*)malloc(sizeof(int) * st->x)));
		if (!fill_lineint(w, st->map[i]))
			return (0);
		free_all(w, l);
		i++;
	}
	return (1);
}
