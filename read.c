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
	st->map->height = y;
	close(fd);
	return (1);
}

int	ft_cp2darr(char **dst, char **src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		MALLCHECK((dst[i] = (char *)malloc(ft_strlen(src[i]))));
		ft_strcpy(dst[i], src[i]);
	}
	return (1);
}

int		map_old_solve(t_fdf *st, char *l, int i)
{
	char	**w;

	w = ft_strsplit(l, ' ');
	if (i == 0)
		st->map->width = count_words(w);
	else if (st->map->width != count_words(w) || st->map->width == 0)
		return (0);
	MALLCHECK((st->map_old[i] = (char **)malloc(sizeof(char *) * st->map->width)));
	ft_cp2darr(st->map_old[i], w, st->map->width);
	free_all(w, l);
	return (1);
}

int		fillall_validate(t_fdf *st)
{
	int		fd;
	char	*l;
	int		i;

	MALLCHECK((st->map = (t_map *)malloc(sizeof(t_map))));
	if (((fd = open(st->n, O_RDONLY)) == -1) || !(count_y(st)))
		return (0);
	i = 0;
	st->map->width = 0;
	MALLCHECK((st->map_old = (char ***)malloc(sizeof(char **) * st->map->height)));
	while (get_next_line(fd, &l) > 0 && i < st->map->height)
	{
		map_old_solve(st, l, i);
		i++;
	}
	return (1);
}
