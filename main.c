/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/19 14:37:12 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	move_fdf(int key, t_fdf *st)
{
	if (key == UP)
		st->cam->shift_y -= H / 25;
	if (key == DOWN)
		st->cam->shift_y += H / 25;
	if (key == LEFT)
		st->cam->shift_x -= W / 40;
	if (key == RIGHT)
		st->cam->shift_x += W / 40;
	prepare_points(st);
	draw(st);
}

int		deal_key(int key, void *st)
{
	if (key == ESC)
		exit (0);
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move_fdf(key, st);
	if (key == SPACE)
	{
		p_arr_init(st);
		set_colours(st);
		p_arr_add_scale_n_shift(st);
		prepare_points(st);
		((t_fdf *)st)->cam->shift_x = 0;
		((t_fdf *)st)->cam->shift_y = 0;
		draw(st);
	}	
	return (0);
}

int		ft_get_colour(char *str)
{
	char **w;

	w = ft_strsplit(str, ',');
	if (count_words(w) == 1)
		return (-1);
	return(ft_atoi_base(ft_strsub(w[1], 2, 6), 16));
}

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

int		p_arr_init(t_fdf *st)
{
	int 	i;
	int 	j;
	t_point *curr;
	int		curr_pos;
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
			curr_pos = map->width * i + j;
			curr = &(map->points[curr_pos]);
			curr->x = j;
			curr->y = i;
			curr->z = ft_atoi(ft_strsplit(st->map_old[i][j], ',')[0]);
			map->max_z = curr->z > map->max_z ? curr->z : map->max_z;
			map->min_z = curr->z < map->min_z ? curr->z : map->min_z;
			curr->colour = ft_get_colour(st->map_old[i][j]);
			map->has_colour = curr->colour != -1 ? 1 : map->has_colour;
			curr->right = j != map->width - 1 ? &(map->points[curr_pos + 1]) : NULL;
			curr->down = i != map->height - 1 ? &(map->points[curr_pos + map->width]) : NULL;
			j++;
		}
		i++;
	}
	r_d_for_iso(map);
	return (1);
}

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
		p->x = p->x * st->scale + st->shx;
		p->y = p->y * st->scale + st->shy;
		p->z = p->z * st->scale;
		p++;
		i++;
	}
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
	p_arr_add_scale_n_shift(st);
	MALLCHECK((st->cam = (t_cam *)malloc(sizeof(t_cam))));
	st->cam->shift_x = 0;
	st->cam->shift_y = 0;
	return (1);
}

void	prepare_points(t_fdf *st)
{
	int i;
	t_map *map;

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

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		ft_putendl_fd("Error!", 2);
		return (0);
	}
	printf("%f\n", st.scale);
	prepare_points(&st);
	draw(&st);
	//mlx_pixel_put(st.mlx_ptr, st.win_ptr, 1, 1, COLOR);
    //mlx_pixel_put(st.mlx_ptr, st.win_ptr, 251, 250, 0x999999);
	mlx_key_hook(st.win_ptr, deal_key, (void *)&st);
	mlx_loop(st.mlx_ptr);
}
