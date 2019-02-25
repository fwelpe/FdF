#include "fdf.h"

void	rotate(t_point *p, t_cam *r, t_fdf *st)
{
	double		x;
	double		y;
	double		z;

	if (!st)
	;
	x = p->x;
	z = p->z;
	p->x = cos(r->y) * x + sin(r->y) * z;
	p->z = -sin(r->y) * x + cos(r->y) * z;
	y = p->y;
	z = p->z;
	p->y = cos(r->x) * y - sin(r->x) * z;
	p->z = sin(r->x) * y + cos(r->x) * z;
}

void	zero_cam(t_fdf *st)
{
	if (st->map->width > st->map->height)
		st->cam->scale = (float)W * (1 - INDENT_PCT * 2) / st->map->width;
	else
		st->cam->scale = (float)H * (1 - INDENT_PCT * 2) / st->map->height;
	st->cam->shift_x = 0;
	st->cam->shift_y = 0;
	st->cam->x = 0;
	st->cam->y = 0;
}