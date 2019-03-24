/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:02:03 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/24 18:01:29 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_fdf(int key, t_fdf *st)
{
	if (key == UP)
		st->cam->move_y += H / 25;
	if (key == DOWN)
		st->cam->move_y -= H / 25;
	if (key == LEFT)
		st->cam->move_x += W / 40;
	if (key == RIGHT)
		st->cam->move_x -= W / 40;
	copy_points(st->map);
	draw(st);
}

void	handle_space(t_fdf *st)
{
	zero_cam(st);
	copy_points(st->map);
	draw(st);
}

int		deal_key(int key, t_fdf *st)
{
	if (key == ESC)
		exit(0);
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move_fdf(key, st);
	if (key == SPACE)
	{
		handle_space(st);
	}
	if (key == PLUS || key == MINUS)
		zoom_fdf(key, st);
	return (0);
}

int		red_button(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
