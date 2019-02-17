/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/17 20:58:22 by fwlpe            ###   ########.fr       */
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

void	calc_scale_n_shift(t_fdf *st)
{
	if (st->x > st->y)
	{
		st->scale = (float)W * (1 - INDENT_PCT * 2) / st->x;
		st->shx = W * INDENT_PCT;
		st->shy = (H - st->scale * st->y) / 2;
	}
	else
	{
		st->scale = (float)H * (1 - INDENT_PCT * 2) / st->y;
		st->shy = H * INDENT_PCT;
		st->shx = (W - st->scale * st->x) / 2;
	}	
}

/* void	calc_scale_n_shift(t_fdf *st)
{
	float	tmp;

	tmp = (float)H * (1 - INDENT_PCT * 2) / st->y;
	st->scale = (float)W * (1 - INDENT_PCT * 2) / st->x;
	st->scale = tmp < st->scale ? tmp : st->scale;
	st->shx = (float)W * INDENT_PCT;
	st->shy = (float)H * INDENT_PCT;
} */

int		p_arr_init(t_fdf *st)
{
	int i;
	int j;

	MALLCHECK((st->p_arr = (t_point*)malloc(sizeof(t_point) * st->x * st->y)));
	i = 0;
	while (i < st->y)
	{
		j = 0;
		while (j < st->x)
		{
			st->p_arr[st->x * i + j].x = j;
			st->p_arr[st->x * i + j].y = i;
			st->p_arr[st->x * i + j].z = st->map[i][j];
			if (j != st->x - 1)
				st->p_arr[st->x * i + j].right =
			  &(st->p_arr[st->x * i + j + 1]);
			else
				st->p_arr[st->x * i + j].right = NULL;
			if (i != st->y - 1)
				st->p_arr[st->x * i + j].down =
			  &(st->p_arr[st->x * (i + 1) + j]);
			else
				st->p_arr[st->x * i + j].down = NULL;
			j++;
		}
		i++;
	}
	return (1);
}

void	p_arr_add_scale_n_shift(t_fdf *st)
{
	int		i;
	t_point	*p;

	i = 0;
	p = st->p_arr;
	while (i < st->x * st->y)
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
	if (!fillall_validate(st) || !p_arr_init(st))
		return (0);
	calc_scale_n_shift(st);
	p_arr_add_scale_n_shift(st);
	st->ax = PI / 6;
	st->ay = PI / 6;
	st->az = 0;
	return (1);
}

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		printf("Error!\n");
		return (0);
	}
	printf("%f\n", st.scale);
	draw(&st);
	//mlx_pixel_put(st.mlx_ptr, st.win_ptr, 1, 1, COLOR);
    //mlx_pixel_put(st.mlx_ptr, st.win_ptr, 251, 250, 0x999999);
	mlx_key_hook(st.win_ptr, deal_key, (void *)0);
	mlx_loop(st.mlx_ptr);

}
