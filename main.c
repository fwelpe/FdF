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

int		deal_key(int key, void *param)
{
	if (!param)
	;
	if (key == 53)
		exit (0);
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

int		p_arr_init(t_fdf *st)
{
	int 	i;
	int 	j;
	// int		k;
	t_point *curr;
	int		curr_pos;

	
	MALLCHECK((st->map->points = (t_point *)malloc(sizeof(t_point) * st->map->width * st->map->height)));
	i = 0;
	while (i < st->map->height)
	{
		j = 0;
		while (j < st->map->width)
		{
			curr_pos = st->map->width * i + j;
			curr = &(st->map->points[curr_pos]);
			curr->x = j;
			curr->y = i;
			curr->z = ft_atoi(ft_strsplit(st->map_old[i][j], ',')[0]);
			curr->colour = ft_get_colour(st->map_old[i][j]);
			curr->right = j != st->map->width - 1 ? &(st->map->points[curr_pos + 1]) : NULL;
			curr->down = i != st->map->height - 1 ? &(st->map->points[curr_pos + st->map->width]) : NULL;
			j++;
		}
		i++;
	}
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
	p_arr_add_scale_n_shift(st);
	return (1);
}

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		ft_putendl_fd("Error!", 2);
		return (0);
	}
	draw(&st);
	//mlx_pixel_put(st.mlx_ptr, st.win_ptr, 1, 1, COLOR);
    //mlx_pixel_put(st.mlx_ptr, st.win_ptr, 251, 250, 0x999999);
	mlx_key_hook(st.win_ptr, deal_key, (void *)0);
	mlx_loop(st.mlx_ptr);
}
