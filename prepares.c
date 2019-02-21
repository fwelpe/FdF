#include "fdf.h"

int	r_d_for_iso(t_map *map)
{
	int 	i;
	int 	j;
	t_point *curr;
	int		curr_pos;

	i = 0;
	MALLCHECK((map->iso = (t_point *)malloc(sizeof(t_point) * map->width * map->height)));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			curr_pos = map->width * i + j;
			curr = &(map->iso[curr_pos]);
			curr->right = j != map->width - 1 ? &(map->iso[curr_pos + 1]) : NULL;
			curr->down = i != map->height - 1 ? &(map->iso[curr_pos + map->width]) : NULL;
			j++;
		}
		i++;
	}
	return (1);
}

void	p_arr_solve(t_fdf *st, int i, int j)
{
	t_point *curr;
	int		curr_pos;
	t_map	*map;

	map = st->map;
	curr_pos = map->width * i + j;
	curr = &(map->points[curr_pos]);
	curr->x = j;
	curr->y = i;
	curr->z = ft_atoi(ft_strsplit(st->map_old[i][j], ',')[0]);
	map->max_z = curr->z > map->max_z ? curr->z : map->max_z;
	map->min_z = curr->z < map->min_z ? curr->z : map->min_z;
	curr->colour = get_colour(st->map_old[i][j]);
	map->has_colour = curr->colour != -1 ? 1 : map->has_colour;
	curr->right = j != map->width - 1 ? &(map->points[curr_pos + 1]) : NULL;
	curr->down = i != map->height - 1 ? &(map->points[curr_pos + map->width]) : NULL;
}

int		p_arr_init(t_fdf *st)
{
	int 	i;
	int 	j;
	t_map	*map;

	map = st->map;
	map->has_colour = 0;
	map->max_z = ft_atoi(ft_strsplit(st->map_old[0][0], ',')[0]);
	map->min_z = map->max_z;
	MALLCHECK((map->points = (t_point *)malloc(sizeof(t_point) * map->width * map->height)));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			p_arr_solve(st, i, j);
			j++;
		}
		i++;
	}
	r_d_for_iso(map);
	return (1);
}

int		st_init(t_fdf *st, char *n)
{
	st->mlx_ptr = mlx_init();
	st->win_ptr = mlx_new_window(st->mlx_ptr, W, H, "FdF 42");
	st->n = n;
	if(!(st->image = new_image(st)))
		return (0);
	if (!fillall_validate(st) || !p_arr_init(st))
		return (0);
	calc_scale_n_shift(st);
	set_colours(st);
	MALLCHECK((st->cam = (t_cam *)malloc(sizeof(t_cam))));
	zero_cam(st);
	p_arr_add_scale_n_shift(st);
	return (1);
}

void	prepare_points(t_fdf *st)
{
	int i;
	t_map *map;

	p_arr_del_shift(st);
	p_arr_add_scale_n_shift(st);
	map = st->map;
	i = -1;
	while (++i < map->height * map->width)
	{
		map->iso[i].colour = map->points[i].colour;
		map->iso[i].x = map->points[i].x;
		map->iso[i].y = map->points[i].y;
		map->iso[i].z = map->points[i].z;
	}
}