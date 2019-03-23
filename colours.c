/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:31:28 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/23 17:13:49 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_p_col(double max, double min, int z, t_colours colours)
{
	int res[3];
	int c1;
	int c2;
	int i;

	i = 0;
	c1 = colours.frstcol >> 16;
	c2 = colours.scndcol >> 16;
	while (i < 3)
	{
		if (c1 > c2)
			res[i] = c2 + ((z - min) / (max - min)) * (c1 - c2);
		else
			res[i] = c2 - ((z - min) / (max - min)) * (c2 - c1);
		c1 = i == 0 ? (colours.frstcol & 0xFF00) >> 8 : colours.frstcol & 0xFF;
		c2 = i == 0 ? (colours.scndcol & 0xFF00) >> 8 : colours.scndcol & 0xFF;
		i++;
	}
	return ((res[0] << 16) | (res[1] << 8) | res[2]);
}

int		get_colour(char *str)
{
	char	*p;

	p = ft_strchr(str, ',');
	if (!p)
		return (-1);
	return (ft_atoi_base(p + 3, 16));
}

int		gradient(t_colours colours, float dx, float dy, int n)
{
	float len;

	len = sqrt(pow(dx, 2) + pow(dy, 2));
	return (get_p_col(len, 0, n, colours));
}

void	set_colours(t_fdf *st)
{
	t_point		*p;
	int			i;
	t_colours	c;

	c.frstcol = TO;
	c.scndcol = FROM;
	i = -1;
	p = st->map->base_p;
	if (st->map->has_colour)
		while (++i < st->map->square)
		{
			p->colour = p->colour == -1 ? COLOUR : p->colour;
			p++;
		}
	else
	{
		while (++i < st->map->square)
		{
			if (st->map->max_z == st->map->min_z)
				p->colour = FLAT;
			else
				p->colour = get_p_col(st->map->max_z, st->map->min_z, p->z, c);
			p++;
		}
	}
}
