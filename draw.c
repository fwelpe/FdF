/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/02/15 20:41:40 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void iso(float *x, float *y, float z)
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
	return (f + 0.5);
}

void	sort_by_coord(t_point *p1, t_point *p2, char c)
{
	t_point *t;
	
	if ((c == 'x' && p1->x > p2->x) || (c == 'y' && p1->y > p2 -> y))
	{
		t = p1;
		p1 = p2;
		p2 = t;
	}
}

void	draw_line(t_point p1, t_point p2, t_fdf *st)
{
	float	deltax;
	float	deltay;
	float	x;
	float	y;
	float	shift;

	deltax = fabsf(p1.x - p2.x);
    deltay = fabsf(p1.y - p2.y);
	if (deltax > deltay)
	{
		sort_by_coord(&p1, &p2, 'x');
		x = p1.x;
		y = p1.y;
		shift = deltay / deltax * (p1.y < p2.y ? 1 : -1);
		while (x <= p2.x)
		{
			mlx_pixel_put(st->mlx_ptr, st->win_ptr, x, ftoi(y), COLOR);
			y += shift;
			x++;
		}
	}
	else
	{
		sort_by_coord(&p1, &p2, 'y');
		x = p1.x;
		y = p1.y;
		shift = deltax / deltay * (p1.x < p2.x ? 1 : -1);
		while (y <= p2.y)
		{
			mlx_pixel_put(st->mlx_ptr, st->win_ptr, ftoi(x), y, COLOR);
			x += shift;
			y++;
		}
	}
}

/* void	draw_line(t_point p1, t_point p2, t_fdf *st)
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
} */

void	draw(t_fdf *st)
{
	int	i;
	t_point *p;

	while (i < st->x * st->y)
	{
		if (st->p_arr[i].right)
		{
			//iso(&(st->p_arr[i].x), &(st->p_arr[i].y), st->p_arr[i].z);
			//iso(&(st->p_arr[i].right->x), &(st->p_arr[i].right->y), st->p_arr[i].right->z);
			draw_line(st->p_arr[i], *(st->p_arr[i].right), st);
		}
		if (st->p_arr[i].down)
		{
			//iso(&(st->p_arr[i].x), &(st->p_arr[i].y), st->p_arr[i].z);
			//iso(&(st->p_arr[i].down->x), &(st->p_arr[i].down->y), st->p_arr[i].down->z);
			draw_line(st->p_arr[i], *(st->p_arr[i].down), st);
		}
		i++;
	}
}
