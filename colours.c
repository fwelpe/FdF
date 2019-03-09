#include "fdf.h"

double get_p_colour(double max, double min, int z, t_colours colours)
{
	int res[3];
	int c1;
	int c2;
	int i;

	i = 0;
	c1 = colours.frstCol >> 16;
	c2 = colours.scndCol >> 16;
	while (i < 3)
	{
		if (c1 > c2)
			res[i] = c2 + ((z - min) / (max - min)) * (c1 - c2);
		else
			res[i] = c2 - ((z - min) / (max - min)) * (c2 - c1);
		c1 = i == 0 ? (colours.frstCol & 0xFF00) >> 8 : colours.frstCol & 0xFF;
		c2 = i == 0 ? (colours.scndCol & 0xFF00) >> 8 : colours.scndCol & 0xFF;
		i++;
	}
	return ((res[0] << 16) | (res[1] << 8) | res[2]);
}

int get_colour(char *str)
{
	char **w;

	w = ft_strsplit(str, ',');
	if (count_words(w) == 1)
		return (-1);
	return (ft_atoi_base(ft_strsub(w[1], 2, 6), 16));
}

int gradient(t_colours colours, float dx, float dy, int n)
{
	float len;

	len = sqrt(pow(dx, 2) + pow(dy, 2));
	return (get_p_colour(len, 0, n, colours));
}

void set_colours(t_fdf *st)
{
	t_point *p;
	int i;
	t_colours colours;

	colours.frstCol = TO;
	colours.scndCol = FROM;
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
				p->colour = get_p_colour(st->map->max_z, st->map->min_z, p->z,
										 colours);
			p++;
		}
	}
}