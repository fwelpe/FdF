#include "fdf.h"

void	zero_cam(t_fdf *st)
{
	st->cam->shift_x = 0;
	st->cam->shift_y = 0;
	st->cam->scale = pow(st->scale, 2);
}