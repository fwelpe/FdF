#include "fdf.h"

void iso(float *x, float *y, float z)
{
    float previous_x;
    float previous_y;
    previous_x = *x - (W / 2);
    previous_y = *y - (H / 2);
    *x = (previous_x - previous_y) * cos(0.523599) + W / 2;
    *y = -z + (previous_x + previous_y) * sin(0.523599) + H / 2;
}

void	prepare_iso(t_fdf *st)
{
	int	i;
	t_point *p;
	t_map *map;

	i = 0;
	p = st->map->iso;
	map = st->map;
	while (i < map->width * map->height)
	{
		iso(&(p[i].x), &(p[i].y), p[i].z);
		p[i].x += st->cam->shift_x;
		p[i].y += st->cam->shift_y;
		i++;
	}
}