#include "fdf.h"

// void	calc_scale_n_shift(t_fdf *st)
// {
	
// }

void	p_arr_add_scale_n_shift(t_fdf *st)
{
	int		i;
	t_point	*p;

	i = 0;
	p = st->map->points;
	while (i < st->map->width * st->map->height)
	{
		p->x = p->x / st->cam->scale + st->shx;
		p->y = p->y / st->cam->scale + st->shy;
		p->z = p->z / st->cam->scale;
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