#include "fdf.h"

double		get_p_colour(double max, double min, int z, int col1, int col2)
{
	int		res[3];
	int		c1;
	int		c2;
	int		i;

	i = 0;
	c1 = col1 >> 16;
	c2 = col2 >> 16;
	while (i < 3)
	{
		if (c1 > c2)
			res[i] = c2 + ((z - min) / (max - min)) * (c1 - c2);
		else
			res[i] = c2 - ((z - min) / (max - min)) * (c2 - c1);
		c1 = i == 0 ? (col1 & 0xFF00) >> 8 : col1 & 0xFF;
		c2 = i == 0 ? (col2 & 0xFF00) >> 8 : col2 & 0xFF;
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
	return(ft_atoi_base(&(p[3]), 16));
}

int		gradient(int colour1, int colour2, float dx, float dy, int n)
{
	float	len;

	len = sqrt(pow(dx, 2) + pow(dy, 2));
	return (get_p_colour(len, 0, n, colour1, colour2));
}

void	set_colours(t_fdf *st)
{
	t_point	*p;
	int		i;

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
				p->colour = get_p_colour(st->map->max_z, st->map->min_z, p->z, TO, FROM);
			p++;
		}
	}
	
}