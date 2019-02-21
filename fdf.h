/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:48:54 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/18 18:16:10 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>

# define W 1200
# define H 700
# define TO AQUA
# define FROM PURPLE
# define COLOUR SPRING
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
#define UP 126
# define MALLCHECK(x) if (!x) return (0)
# define INDENT_PCT 0.35

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
	int		width;
	int		height;
	int		min_z;
	int		max_z;
	int		has_colour;
	t_point	*points;
	t_point	*iso;
}					t_map;

typedef struct	s_cam
{
	int		shift_x;
	int		shift_y;
	float		scale;
}				t_cam;

typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*n;
	char			***map_old;
	float			scale;
	int				shx;
	int				shy;
	t_map			*map;
	t_image			*image;
	t_cam			*cam;
}				t_fdf;

void			free_doublechar(char **w);
void			free_line(char *l);
void			free_all(char **w, char *l);
int				count_words(char **splitted_words);
int				count_y(t_fdf *st);
int				fillall_validate(t_fdf *st);
//void			draw_lines(t_fdf *st);
void			draw(t_fdf *st);
t_image			*new_image(t_fdf *st);
int				ft_atoi_base(char *nb, int base);
char			*ft_itoa_base(int value, int base);
int		st_init(t_fdf *st, char *n);
void	prepare_points(t_fdf *st);

int				deal_key(int key, void *st);
void	p_arr_add_scale_n_shift(t_fdf *st);
void	p_arr_del_shift(t_fdf *st);
void	calc_scale_n_shift(t_fdf *st);
int		get_colour(char *str);
int		gradient(int colour1, int colour2, float dx, float dy, int n);
void			set_colours(t_fdf *st);
int		p_arr_init(t_fdf *st);
void			prepare_iso(t_fdf *st);
void	image_set_pixel(t_image *image, int x, int y, int color);
void	clear_image(t_image *image);
void	zero_cam(t_fdf *st);
int		ft_pow(int nb, int pow);

#endif
