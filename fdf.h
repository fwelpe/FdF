/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:48:54 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/08 18:20:48 by fwlpe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdio.h>

# define W 1200
# define H 700
# define INDENT_PCT 0.3

# define TO AQUA
# define FROM PURPLE
# define COLOUR SPRING
# define FLAT YELLOW

# define PURPLE 0x9900FF
# define AQUA 0x00FFFF
# define YELLOW 0xFFFF00
# define SPRING 0x99FF00

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define SPACE 49
# define PLUS 24
# define MINUS 27
# define UP 126

# define MALLCHECK(x) if (!x) return (0)

typedef struct	s_point
{
	float			x;
	float			y;
	float			z;
	int				colour;
	struct s_point	*right;
	struct s_point	*down;
}				t_point;

typedef struct		s_image
{
	void		*image_cont;
	char		*adr;
	int			b_p_pix;
}					t_image;

typedef struct		s_map
{
	char		***str_map;
	int		width;
	int		height;
	int		square;
	int		min_z;
	int		max_z;
	int		has_colour;
	t_point	*base_p;
	t_point	*work_p;
}					t_map;

typedef struct	s_cam
{
	float	x;
	float	y;
	float	move_x;
	float	move_y;
	float	center_x;
	float	center_y;
	float	nul_x;
	float	nul_y;
	int		zoom;
	float	scale;
}				t_cam;

typedef struct		s_mouse
{
	int		button;
	int		x;
	int		y;
	int		lastx;
	int		lasty;
}					t_mouse;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*n;
	int			is_scale;
	t_map		*map;
	t_image		*image;
	t_cam		*cam;
	t_mouse		*mouse;
}				t_fdf;

void		free_all(char **w, char *l);
int			count_words(char **splitted_words);
int			fillall_validate(t_map *map, char* name);
void		draw(t_fdf *st);
t_image		*new_image(t_fdf *st);
int			ft_atoi_base(char *nb, int base);
char		*ft_itoa_base(int value, int base);
int			st_init(t_fdf *st, char *n);
void		copy_points(t_map *map);
int			deal_key(int key, t_fdf *st);
int			get_colour(char *str);
int			gradient(int colour1, int colour2, float dx, float dy, int n);
void		set_colours(t_fdf *st);
void		prepare_points(t_fdf *st);
void		image_set_pixel(t_image *image, int x, int y, int color);
void		clear_image(t_image *image);
void		zero_cam(t_fdf *st);
int			ft_pow(int nb, int pow);
int			init_mouse(t_fdf *st);
int 		mouse_press(int button, int x, int y, t_fdf *st);
int 		mouse_release(int button, int x, int y, t_fdf *st);
int 		mouse_move(int x, int y, t_fdf *st);
void		rotate(t_point *p, t_cam *cam);
char		*get_name(char *path);
void		get_scale(t_fdf *st);
void		add_scale(t_map *map, t_cam *cam);
int			r_d_for_work(t_map *map);

#endif
