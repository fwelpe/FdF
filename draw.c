/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/02/13 20:57:55 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	prepare_draw(float x1, float y1, float x2, float y2, t_fdf *st)
{
	/* iso(&x1, &y1, z1);
	iso(&x2, &y2, z2); */

	draw_line(x1, y1, x2, y2, st);
}

void ft_swap(int *q, int *w)
{
	int t;

	if (*q < *w)
	{
		t = *q;
		*q = *w;
		*w = t;
	}
}

void	draw_line(int x1, int y1, int x2, int y2, t_fdf *st)
{
	float	shift;
	float	shift_i;
	int		deltax;
	int		deltay;
	int		x;
	int		y;
	int		diry;

	ft_swap(&(x1), &(x2));
	ft_swap(&(y1), &(y2));
	deltax = abs(x1 - x2);
    deltay = abs(y1 - y2);
	shift = 0;
	shift_i = (float)deltay / deltax;
	y = 0;
	diry = y1 - y2;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	x = x2;
	while (x <= x1)
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

void	draw_lines(t_fdf *st)
{
	int	i;
	int	j;
	float q;

	i = 0;
	q = st->scale;
	while (i < st->y)
	{
		j = 0;
		while (j < st->x)
		{
			if (j != st->x - 1)
				prepare_draw((j + 1) * q, i * q, j * q, i * q, st);
			if (i != st->y - 1)
				prepare_draw(j * q, (i + 1) * q, j * q, i * q, st);
			j++;
		}
		i++;
	}
}