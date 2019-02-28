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

void	find_center(t_map *map, t_cam *cam)
{
	float maxx;
	float minx;
	float maxy;
	float miny;
	int i;

	maxx = map->work_p[0].x;
	minx = maxx;
	maxy = map->work_p[0].y;
	miny = maxy;
	i = 0;
	while (++i < map->square)
	{
		maxx = map->work_p[i].x > maxx ? map->work_p[i].x : maxx;
		minx = map->work_p[i].x < minx ? map->work_p[i].x : minx;
		maxy = map->work_p[i].y > maxy ? map->work_p[i].y : maxy;
		miny = map->work_p[i].y < miny ? map->work_p[i].y : miny;
	}
	cam->center_x = W / 2 - (maxx - minx) / 2 - minx;
	cam->center_y = H / 2 - (maxy - miny) / 2 - miny;
}

void move_points(t_map *map, t_cam *cam)
{
	int		i;
	t_point *p;

	if (cam->zoom == 1)
		find_center(map, cam);
	p = map->work_p;
		i = -1;
	while (++i < map->square)
	{
		p[i].x += cam->move_x + cam->center_x;
		p[i].y += cam->move_y + cam->center_y;
	}
}

void transform_point_coords(t_point *p, t_map *map)
{
	p->x -= (double)(map->width - 1) / 2.0f;
	p->y -= (double)(map->height - 1) / 2.0f;
	p->z -= (double)(map->min_z + map->max_z) / 2.0f;
}

void	prepare_points(t_fdf *st)
{
	int		i;
	t_point *p;
	t_map	*map;

	i = -1;
	p = st->map->work_p;
	map = st->map;
	while (++i < map->square)
	{
		transform_point_coords(&p[i], map);
		rotate(&p[i], st->cam);
		iso(&(p[i].x), &(p[i].y), p[i].z);
		if (st->cam->nul_x == 0 && st->cam->nul_y == 0 && i == 0)
		{
			st->cam->nul_x = p[i].x * -1;
			st->cam->nul_y = p[i].y * -1;
		}
	}
	if (st->is_scale == 1)
		get_scale(st);
	add_scale(map, st->cam);
	move_points(map, st->cam);
	st->cam->zoom = 0;
	st->is_scale = 0;
}