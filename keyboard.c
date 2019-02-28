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

void	zoom_fdf(int key, t_fdf *st)
{
	float	delta;

	delta = (100 / sqrt(pow(st->map->height, 2) + pow(st->map->width, 2)));
	if (key == PLUS)
		st->cam->scale += delta;
	if (key == MINUS && st->cam->scale > delta)
		st->cam->scale -= delta;
	st->cam->zoom = 1;
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
		exit (0);
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