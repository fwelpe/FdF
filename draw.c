/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/02/14 22:55:47 by fwlpe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

int		ftoi(float f)
{
	if (f - (int)f >= 0.5)
		return (f + 1);
	return (f);
}

void	draw_line(t_point p1, t_point p2, t_fdf *st)
{
	float	shift;
	float	shift_i;
	int		deltax;
	int		deltay;
	int		x;
	int		y;
	int		diry;

	deltax = abs(p1.x - p2.x);
    deltay = abs(p1.y - p2.y);
	shift = 0;
	shift_i = (float)deltay / deltax;
	y = p1.y;
	diry = p1.y - p2.y;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	x = p1.x;
	while (x <= p2.x)
	{
		if (x >= 0 && y >= 0)
			mlx_pixel_put(st->mlx_ptr, st->win_ptr, x, y, COLOR);
		shift += shift_i;
		if (shift >= 0.5)
		{
			y += diry;
			shift -= 1.0;
		}
		x++;
	}
}

void	draw(t_fdf *st)
{
	int	i;
	t_point *p;

	while (i < st->x * st->y)
	{
		if (st->p_arr[i].right)
			draw_line(st->p_arr[i], *(st->p_arr[i].right), st);
		if (st->p_arr[i].down)
			draw_line(st->p_arr[i], *(st->p_arr[i].down), st);
	}
}
