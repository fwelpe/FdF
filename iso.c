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

void	find_center(t_fdf *st)
{
	float maxx;
	float minx;
	float maxy;
	float miny;
	int i;

	maxx = st->map->iso[0].x;
	minx = maxx;
	maxy = st->map->iso[0].y;
	miny = maxy;
	i = 0;
	while (++i < st->map->width * st->map->height)
	{
		maxx = st->map->iso[i].x > maxx ? st->map->iso[i].x : maxx;
		minx = st->map->iso[i].x < minx ? st->map->iso[i].x : minx;
		maxy = st->map->iso[i].y > maxy ? st->map->iso[i].y : maxy;
		miny = st->map->iso[i].y < miny ? st->map->iso[i].y : miny;
	}
	st->cam->shift_x = W / 2 - (maxx - minx) / 2 - minx;
	st->cam->shift_y = H / 2 - (maxy - miny) / 2 - miny;
	printf("sh_x = %f, sh_y = %f\n", st->cam->shift_x, st->cam->shift_y);
	printf("%f, %f, %f, %f\n", maxx, minx, maxy, miny);
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
		p[i].x -= (double)(map->width - 1) / 2.0f;
		p[i].y -= (double)(map->height - 1) / 2.0f;
		p[i].z -= (double)(map->min_z + map->max_z) / 2.0f;
		rotate(&p[i], st->cam, st);
		iso(&(p[i].x), &(p[i].y), p[i].z);
		if (st->shx == 0 && st->shy == 0 && i == 0)
		{
			st->shx = p[i].x * -1;
			st->shy = p[i].y * -1;
		}
		p[i].x *= st->cam->scale;
		p[i].y *= st->cam->scale;
		p[i].x += st->shx * st->cam->scale;
		p[i].y += st->shy * st->cam->scale;
		i++;
	}
	if (st->cam->shift_x == 0 && st->cam->shift_y == 0)
		find_center(st);
	i = -1;
	while (++i < map->width * map->height)
	{
		p[i].x += st->cam->shift_x;
		p[i].y += st->cam->shift_y;
	}
}