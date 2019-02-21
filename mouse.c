#include "fdf.h"

int		mouse(t_fdf *st)
{
	MALLCHECK((st->mouse = (t_mouse *)malloc(sizeof(t_mouse))));
	st->mouse->button = -1;
	st->mouse->x = 0;
	st->mouse->y = 0;
	st->mouse->lastx = 0;
	st->mouse->lasty = 0;
	return (1);
}

int mouse_press(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	printf("button = %d\n", st->mouse->button);
	st->mouse->button = button;
	printf("button = %d\n", st->mouse->button);
	return (0);
}

int mouse_release(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	(void)button;
	st->mouse->button = -1;
	zero_cam(st);
	return (0);
}

int mouse_move(int x, int y, t_fdf *st)
{
	st->mouse->lastx = st->mouse->x;
	st->mouse->lasty = st->mouse->y;
	st->mouse->x = x;
	st->mouse->y = y;
	if (st->mouse->button == 1)
	{
		st->cam->x += (st->mouse->lasty - y) / 200.0f;
		st->cam->y -= (st->mouse->lastx - x) / 200.0f;
		prepare_points(st);
		draw(st);
	}
	
	return (0);
}