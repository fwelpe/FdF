#include "fdf.h"

void	get_scale(t_fdf *st)
{
	float maxx;
	float minx;
	float maxy;
	float miny;
	int i;

	maxx = st->map->work_p[0].x;
	minx = maxx;
	maxy = st->map->work_p[0].y;
	miny = maxy;
	i = 0;
	while (++i < st->map->square)
	{
		maxx = st->map->work_p[i].x > maxx ? st->map->work_p[i].x : maxx;
		minx = st->map->work_p[i].x < minx ? st->map->work_p[i].x : minx;
		maxy = st->map->work_p[i].y > maxy ? st->map->work_p[i].y : maxy;
		miny = st->map->work_p[i].y < miny ? st->map->work_p[i].y : miny;
	}
	i = W < H ? W : H;
	if ((maxx - minx) > (maxy - miny))
		st->cam->scale = (i * (1 - INDENT_PCT * 2) * 2) / (maxx - minx);
	else
		st->cam->scale = (i * (1 - INDENT_PCT * 2) * 2) / (maxy - miny);
}

void add_scale(t_map *map, t_cam *cam)
{
	int		i;
	t_point *p;

	p = map->work_p;
	i = -1;
	while (++i < map->square)
	{
		p[i].x *= cam->scale;
		p[i].y *= cam->scale;
		p[i].x += cam->nul_x * cam->scale;
		p[i].y += cam->nul_y * cam->scale;
	}
}