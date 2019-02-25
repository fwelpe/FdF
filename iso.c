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
	// printf("x = %f, y = %f\n", p[0].x, p[0].y);
	while (i < map->width * map->height)
	{
		p[i].x -= (double)(map->width - 1) / 2.0f;
		p[i].y -= (double)(map->height - 1) / 2.0f;
		p[i].z -= (double)(map->min_z + map->max_z) / 2.0f;
		rotate(&p[i], st->cam, st);
		// if (i == 0)
			// printf("rotate x = %f, y = %f\n", p[0].x, p[0].y);
		iso(&(p[i].x), &(p[i].y), p[i].z);
		if (i < 5)
			printf("i = %d, scale x = %f, y = %f\n", i, p[i].x, p[i].y);
		if (st->shx == 0 && st->shy == 0 && i == 0)
		{
			st->shx = p[i].x * -1;
			st->shy = p[i].y * -1;
			printf("min_x = %f, min_y = %f\n", st->shx, st->shy);
		}
		p[i].x *= st->cam->scale;
		p[i].y *= st->cam->scale;
		// if (i != 0)
		// {
		// 	p[i].x -= p[0].x;
		// 	p[i].y -= p[0].y;
			// p[i].x -= st->shx;
			// p[i].y -= st->shy;
			p[i].x += st->shx * st->cam->scale + st->cam->shift_x;
			p[i].y += st->shy * st->cam->scale + st->cam->shift_y;
			// p[i].x -= 7200;
			// p[i].y += 2400;
		// }
		if (i < 5)
			printf("i = %d, scale x = %f, y = %f\n", i, p[i].x, p[i].y);
		i++;
	}
	i = -1;
	// while (++i < map->width * map->height)
	// {
	// 	p[i].x -= min_x;
	// 	p[i].y -= min_y;
	// }
	// p[0].x = st->shx + st->cam->shift_x;
	// p[0].y = st->shy + st->cam->shift_y;
	// printf("shift x = %f, y = %f\n", p[0].x, p[0].y);
}