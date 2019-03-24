/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:54:47 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/24 18:28:02 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_keywords(t_fdf *st)
{
	char *s1;
	char *s2;

	s1 = "Mouse usage supported. Free rotation, drag'n'drop. Scroll for scale";
	s2 = "Arrow keys to move image. Space to reset to iso";
	mlx_string_put(st->mlx_ptr, st->win_ptr, 0, 0, 0xFFFFFF, s1);
	mlx_string_put(st->mlx_ptr, st->win_ptr, 0, 30, 0xFFFFFF, s2);
}

int		erroring(int ac, char *av1)
{
	int		fd;
	char	*s;

	if (ac != 2)
	{
		s = "Usage: ./fdf /path/to/file.fdf\nPath can be absolute or relative.";
		ft_putendl_fd(s, 2);
		return (1);
	}
	if ((fd = open(av1, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Wrong file path. Not found.", 2);
		return (1);
	}
	close(fd);
	return (0);
}
