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
# define PURPLE 0x9900FF
# define AQUA 0x00FFFF
# define SPRING 0x99FF00
# define PI 3.141592653589793238462643
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
}					t_map;


typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*n;
	// int				x;
	// int				y;
	char			***map_old;
	float			scale;
	int				shx;
	int				shy;
	t_map			*map;
	t_image			*image;
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
void			iso(float *x, float *y, float z);
void			prepare(t_fdf *st);
void			set_colours(t_fdf *st);

#endif
