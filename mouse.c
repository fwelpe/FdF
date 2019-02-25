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
	printf("x = %d, y = %d\n", x, y);
	st->mouse->button = button;
	// printf("button = %d\n", st->mouse->button);
	return (0);
}

int mouse_release(int button, int x, int y, t_fdf *st)
{
	(void)x;
	(void)y;
	(void)button;
	st->mouse->button = -1;
	// zero_cam(st);
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
		st->cam->x += (st->mouse->lasty - y) / 50.0f;
		st->cam->y -= (st->mouse->lastx - x) / 50.0f;
		prepare_points(st);
		// printf("x = %f, y = %f\n", st->cam->x, st->cam->y);
		// printf("x = %d, y = %d\nlastx = %d, lasty = %d\ndx = %d, dy = %d\ngyp = %f\n\n", 
		// 	x, y, st->mouse->lastx,st->mouse->lasty, dx, dy, gyp);
		draw(st);
	}
	
	return (0);
}