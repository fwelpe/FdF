/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepares.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:15:00 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/18 14:46:32 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		validate_z(char *str)
{
	int i;

	i = -1;
	while (str[++i] && str[i] != ',')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
		{
			ft_putendl_fd("Error!", 2);
			exit(1);
		}
	}
	return (ft_atoi(str));
}

void	fill_base_p(t_map *map, int i, int j)
{
	t_point *curr;
	int		curr_pos;

	curr_pos = map->width * i + j;
	curr = &(map->base_p[curr_pos]);
	curr->x = j;
	curr->y = i;
	curr->z = validate_z(map->str_map[i][j]);
	map->max_z = curr->z > map->max_z ? curr->z : map->max_z;
	map->min_z = curr->z < map->min_z ? curr->z : map->min_z;
	curr->colour = get_colour(map->str_map[i][j]);
	map->has_colour = curr->colour != -1 ? 1 : map->has_colour;
	curr->right = j != map->width - 1 ? &(map->base_p[curr_pos + 1]) : NULL;
	curr->down =
		i != map->height - 1 ? &(map->base_p[curr_pos + map->width]) : NULL;
}

int		p_arr_init(t_map *map)
{
	int	i;
	int	j;

	map->has_colour = 0;
	map->max_z = validate_z(map->str_map[0][0]);
	map->min_z = map->max_z;
	MALLCHECK((map->base_p = (t_point *)malloc(sizeof(t_point) * map->square)));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			fill_base_p(map, i, j);
			j++;
		}
		i++;
	}
	r_d_for_work(map);
	return (1);
}

int		st_init(t_fdf *st, char *name)
{
	st->mlx_ptr = mlx_init();
	st->win_ptr = mlx_new_window(st->mlx_ptr, W, H, get_name(name));
	if (!(st->image = new_image(st)))
		return (0);
	MALLCHECK((st->map = (t_map *)malloc(sizeof(t_map))));
	if (!fillall_validate(st->map, name) || !p_arr_init(st->map))
		return (0);
	set_colours(st);
	MALLCHECK((st->cam = (t_cam *)malloc(sizeof(t_cam))));
	zero_cam(st);
	return (1);
}
