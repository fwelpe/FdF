/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:43 by fwlpe             #+#    #+#             */
/*   Updated: 2019/02/18 18:25:17 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	*(int *)(image->adr + ((x + y * W) * image->b_p_pix)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->adr, W * H * image->b_p_pix);
}

t_image	*del_image(t_fdf *st, t_image *img)
{
	if (img != NULL)
	{
		if (img->image_cont != NULL)
			mlx_destroy_image(st->mlx_ptr, img->image_cont);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*new_image(t_fdf *st)
{
	t_image		*img;
	int	nil = 0;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(img->image_cont = mlx_new_image(st->mlx_ptr, W, H)))
		return (del_image(st, img));
	img->adr = mlx_get_data_addr(img->image_cont, &img->b_p_pix, &nil,
			&nil);
	img->b_p_pix /= 8;
	return (img);
}

void iso(float *x, float *y, float z)
{
    float previous_x;
    float previous_y;
    previous_x = *x - (W / 2);
    previous_y = *y - (H / 2);
    *x = (previous_x - previous_y) * cos(0.523599) + W / 2;
    *y = -z + (previous_x + previous_y) * sin(0.523599) + H / 2;
}

int		ftoi(float f)
{
	return (f + 0.5);
}

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

void	draw_line(t_point p1, t_point p2, t_fdf *st)
{
	float	deltax;
	float	deltay;
	float	x;
	float	y;
	float	shift;

	deltax = fabsf(p1.x - p2.x);
    deltay = fabsf(p1.y - p2.y);
	if (deltax > deltay)
	{
		sort_by_coord(&p1, &p2, 'x');
		x = p1.x;
		y = p1.y;
		shift = deltay / deltax * (p1.y < p2.y ? 1 : -1);
		while (x <= p2.x)
		{
			if (x >=0 && x <= W && y >= 0 && y <= H)
				image_set_pixel(st->image, x, y, p1.colour);
			y += shift;
			x++;
		}
	}
	else
	{
		sort_by_coord(&p1, &p2, 'y');
		x = p1.x;
		y = p1.y;
		shift = deltax / deltay * (p1.x < p2.x ? 1 : -1);
		while (y <= p2.y)
		{
			if (x >=0 && x <= W && y >= 0 && y <= H)
				image_set_pixel(st->image, x, y, p1.colour);
			x += shift;
			y++;
		}
	}
}

double		get_height_colours(double max, double min, int z)
{
	int     red;
    int     green;
    int     blue;
	int     red2 = 0x99;
    int     green2 = 0x00;
    int     blue2 = 0xFF;
	int     red1 = 0x00;
    int     green1 = 0xFF;
    int     blue1 = 0xFF;
	int		c1;
	int		c2;
	int		colour;
	double	perc;

	perc = (z - min) / (max - min);
	// printf ("z = %d, max = %f, min = %f, perc = %f\n",z, max, min, perc);
	c1 = red1;
	c2 = red2;
	if (c1 > c2)
		colour = c2 + perc * (c1 - c2);
	else
		colour = c2 - perc * (c2 - c1);
	red = colour;

	c1 = green1;
	c2 = green2;
	if (c1 > c2)
		colour = c2 + perc * (c1 - c2);
	else
		colour = c2 - perc * (c2 - c1);
	green = colour;

	c1 = blue1;
	c2 = blue2;
	if (c1 > c2)
		colour = c2 + perc * (c1 - c2);
	else
		colour = c2 - perc * (c2 - c1);
	blue = colour;
	// printf("red = %02X, green = %02X, blue = %02X\n", red, green, blue);
    return ((red << 16) | (green << 8) | blue);
}

void	set_colours(t_fdf *st)
{
	t_point	*p;
	int		i;

	i = -1;
	p = st->map->points;
	if (st->map->has_colour)
		while (++i < st->map->width * st->map->height)
		{
			p->colour = p->colour == -1 ? SPRING : p->colour;
			p++;
		}
	else
	{
		while (++i < st->map->width * st->map->height)
		{
			p->colour = get_height_colours(st->map->max_z, st->map->min_z, p->z);
			// printf("z = %f, colour = %06X\n", p->z, p->colour);
			p++;
		}
	}
	
}

void	draw(t_fdf *st)
{
	int	i;
	t_point *p;

	p = st->map->points;
	clear_image(st->image);
	i = 0;
	while (i < st->map->width * st->map->height)
	{
		if (p[i].right)
			draw_line(p[i], *(p[i].right), st);
		if (p[i].down)
			draw_line(p[i], *(p[i].down), st);
		i++;
	}
	mlx_put_image_to_window(st->mlx_ptr, st->win_ptr, st->image->image_cont, 0, 0);
}
