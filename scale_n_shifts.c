#include "fdf.h"

void	calc_scale_n_shift(t_fdf *st)
{
	if (st->map->width > st->map->height)
	{
		st->scale = (float)W * (1 - INDENT_PCT * 2) / st->map->width;
		st->shx = W * INDENT_PCT;
		st->shy = (H - st->scale * st->map->height) / 2;
	}
	else
	{
		st->scale = (float)H * (1 - INDENT_PCT * 2) / st->map->height;
		st->shy = H * INDENT_PCT;
		st->shx = (W - st->scale * st->map->width) / 2;
	}
}

void	p_arr_add_scale_n_shift(t_fdf *st)
{
	int		i;
	t_point	*p;

	i = 0;
	p = st->map->points;
	while (i < st->map->width * st->map->height)
	{
		p->x = p->x / st->scale * st->cam->scale + st->shx;
		p->y = p->y / st->scale * st->cam->scale + st->shy;
		p->z = p->z / st->scale * st->cam->scale;
		p++;
		i++;
	}
	st->scale = st->cam->scale;
}

void	p_arr_del_shift(t_fdf *st)
{
	int		i;
	t_point	*p;

	i = 0;
	p = st->map->points;
	while (i < st->map->width * st->map->height)
	{
		p->x = p->x - st->shx;
		p->y = p->y - st->shy;
		p++;
		i++;
	}
}