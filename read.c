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

int		count_lines(char *name)
{
	int		fd;
	int		y;
	char	*l;

	if (((fd = open(name, O_RDONLY)) == -1))
		return (0);
	y = 0;
	while (get_next_line(fd, &l) > 0)
	{
		y++;
		free(l);
	}
	free(l);
	close(fd);
	return (y);
}

int		ft_cp2darr(char **dst, char **src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		MALLCHECK((dst[i] = (char *)malloc(ft_strlen(src[i]))));
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	return (1);
}

int		str_map_solve(t_map *map, char *line, int i)
{
	char	**words;

	words = ft_strsplit(line, ' ');
	if (i == 0)
		map->width = count_words(words);
	else if (map->width != count_words(words) || map->width == 0)
		return (0);
	MALLCHECK((map->str_map[i] =
		(char **)malloc(sizeof(char *) * map->width)));
	ft_cp2darr(map->str_map[i], words, map->width);
	free_all(words, line);
	return (1);
}

int		fillall_validate(t_map *map, char* name)
{
	int		fd;
	char	*line;
	int		i;

	if (((fd = open(name, O_RDONLY)) == -1) ||
		!(map->height = count_lines(name)))
		return (0);
	i = 0;
	map->width = 0;
	MALLCHECK((map->str_map =
		(char ***)malloc(sizeof(char **) * map->height)));
	while (get_next_line(fd, &line) > 0 && i < map->height)
	{
		if(!str_map_solve(map, line, i))
			return (0);
		i++;
	}
	free(line);
	close(fd);
	map->square = map->width * map->height;
	return (1);
}
