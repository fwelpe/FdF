/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/03/23 17:13:51 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

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

void	if_dx(t_point p1, t_point p2, t_fdf *st, t_deltas dt)
{
	float		x;
	float		y;
	float		shift;
	t_colours	c;

	sort_by_coord(&p1, &p2, 'x');
	x = p1.x;
	y = p1.y;
	shift = dt.dy / dt.dx * (p1.y < p2.y ? 1 : -1);
	c.frstcol = p2.colour;
	c.scndcol = p1.colour;
	while (x <= p2.x)
	{
		if (x >= 0 && x <= W && y >= 0 && y <= H)
			image_set_pixel(st->image, x, y,
							gradient(c, dt.dx, dt.dy, x - p1.x));
		y += shift;
		x++;
	}
}

void	if_dy(t_point p1, t_point p2, t_fdf *st, t_deltas dt)
{
	float		x;
	float		y;
	float		shift;
	t_colours	c;

	sort_by_coord(&p1, &p2, 'y');
	x = p1.x;
	y = p1.y;
	shift = dt.dx / dt.dy * (p1.x < p2.x ? 1 : -1);
	c.frstcol = p2.colour;
	c.scndcol = p1.colour;
	while (y <= p2.y)
	{
		if (x >= 0 && x <= W && y >= 0 && y <= H)
			image_set_pixel(st->image, x, y,
							gradient(c, dt.dx, dt.dy, y - p1.y));
		x += shift;
		y++;
	}
}

void	draw_line(t_point p1, t_point p2, t_fdf *st)
{
	t_deltas	dt;

	dt.dx = fabsf(p1.x - p2.x);
	dt.dy = fabsf(p1.y - p2.y);
	if (dt.dx > dt.dy)
		if_dx(p1, p2, st, dt);
	else
		if_dy(p1, p2, st, dt);
}

void	draw(t_fdf *st)
{
	int		i;
	t_point	*p;

	p = st->map->work_p;
	prepare_points(st);
	clear_image(st->image);
	i = -1;
	while (++i < st->map->square)
	{
		if (p[i].right)
			draw_line(p[i], *(p[i].right), st);
		if (p[i].down)
			draw_line(p[i], *(p[i].down), st);
	}
	mlx_put_image_to_window(st->mlx_ptr, st->win_ptr, st->image->image_cont,
	0, 0);
}
