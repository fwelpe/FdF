#include "fdf.h"

int	r_d_for_work(t_map *map)
{
	int 	i;
	int 	j;
	t_point *curr;
	int		curr_pos;

	i = 0;
	MALLCHECK((map->work_p = (t_point *)malloc(sizeof(t_point) * map->square)));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			curr_pos = map->width * i + j;
			curr = &(map->work_p[curr_pos]);
			curr->right = j != map->width - 1 ?
				&(map->work_p[curr_pos + 1]) : NULL;
			curr->down = i != map->height - 1 ?
				&(map->work_p[curr_pos + map->width]) : NULL;
			j++;
		}
		i++;
	}
	return (1);
}

void	copy_points(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->square)
	{
		map->work_p[i].colour = map->base_p[i].colour;
		map->work_p[i].x = map->base_p[i].x;
		map->work_p[i].y = map->base_p[i].y;
		map->work_p[i].z = map->base_p[i].z;
	}
}