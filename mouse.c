/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:05:19 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/23 17:23:48 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_mouse(t_fdf *st)
{
	MALLCHECK((st->mouse = (t_mouse *)malloc(sizeof(t_mouse))));
	st->mouse->button = -1;
	st->mouse->x = 0;
	st->mouse->y = 0;
	st->mouse->lastx = 0;
	st->mouse->lasty = 0;
	return (1);
}

int	mouse_press(int button, int x, int y, t_fdf *st)
{
	(void)x;
	if (y >= 0)
		st->mouse->button = button;
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	(void)button;
	st->mouse->button = -1;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *st)
{
	st->mouse->lastx = st->mouse->x;
	st->mouse->lasty = st->mouse->y;
	st->mouse->x = x;
	st->mouse->y = y;
	if (st->mouse->button == 1)
	{
		st->cam->x += (st->mouse->lasty - y) / 150.0f;
		st->cam->y -= (st->mouse->lastx - x) / 150.0f;
		copy_points(st->map);
		draw(st);
	}
	return (0);
}
