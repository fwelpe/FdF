/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/02/18 18:25:17 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void iso(float *x, float *y, float z)
{
    float previous_x;
    float previous_y;
    previous_x = *x - (W / 2);
    previous_y = *y - (H / 2);
    *x = (previous_x - previous_y) * cos(0.523599) + W / 2;
    *y = -z + (previous_x + previous_y) * sin(0.523599) + H / 2;
}

int		ftoi(float f)
{
	return (f + 0.5);
}

void	sort_by_coord(t_point *p1, t_point *p2, char c)
{
	t_point t;
	
	if ((c == 'x' && p1->x > p2->x) || (c == 'y' && p1->y > p2->y))
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
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
		while (x <= p2.x + 1)
		{
			if (x >=0 && x <= W && y >= 0 && y <= H)
				mlx_pixel_put(st->mlx_ptr, st->win_ptr, x, y, COLOR);
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
			if (x >=0 && x <= W && y >= 0 && y <= H)
				mlx_pixel_put(st->mlx_ptr, st->win_ptr, x, y, COLOR);
			x += shift;
			y++;
		}
	}
}

void	draw(t_fdf *st)
{
	int	i;
	t_point *p;

	i = 0;
	p = st->p_arr;
	while (i < st->x * st->y)
	{
		iso(&(st->p_arr[i].x), &(st->p_arr[i].y), st->p_arr[i].z);
		i++;
	}
	i = 0;
	while (i < st->x * st->y)
	{
		if (st->p_arr[i].right)
			draw_line(st->p_arr[i], *(st->p_arr[i].right), st);
		if (st->p_arr[i].down)
			draw_line(st->p_arr[i], *(st->p_arr[i].down), st);
		i++;
	}
}
