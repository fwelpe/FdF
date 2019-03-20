/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:07:04 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/18 13:07:06 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_point *p, t_cam *cam)
{
	double		x;
	double		y;
	double		z;

	x = p->x;
	z = p->z;
	p->x = cos(cam->y) * x + sin(cam->y) * z;
	p->z = -sin(cam->y) * x + cos(cam->y) * z;
	y = p->y;
	z = p->z;
	p->y = cos(cam->x) * y - sin(cam->x) * z;
	p->z = sin(cam->x) * y + cos(cam->x) * z;
}

void	zero_cam(t_fdf *st)
{
	st->cam->move_x = 0;
	st->cam->move_y = 0;
	st->cam->center_x = 0;
	st->cam->center_y = 0;
	st->cam->x = 0;
	st->cam->y = 0;
	st->cam->zoom = 1;
	st->is_scale = 1;
	st->cam->nul_x = 0;
	st->cam->nul_y = 0;
}
