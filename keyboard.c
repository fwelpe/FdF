#include "fdf.h"

void	move_fdf(int key, t_fdf *st)
{
	if (key == UP)
		st->cam->shift_y += H / 25;
	if (key == DOWN)
		st->cam->shift_y -= H / 25;
	if (key == LEFT)
		st->cam->shift_x += W / 40;
	if (key == RIGHT)
		st->cam->shift_x -= W / 40;
	prepare_points(st);
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
	prepare_points(st);
	draw(st);
}

void	handle_space(t_fdf *st)
{
	if (st->map->width > st->map->height)
		st->scale = (float)W * (1 - INDENT_PCT * 2) / st->map->width;
	else
		st->scale = (float)H * (1 - INDENT_PCT * 2) / st->map->height;
	zero_cam(st);
	p_arr_init(st);
	set_colours(st);
	// p_arr_add_scale_n_shift(st);
	prepare_points(st);
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