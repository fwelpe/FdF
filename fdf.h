/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:48:54 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/15 20:12:23 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

# define W 1200
# define H 700
# define COLOR 0xff0000
# define PI 3.141592653589793238462643
# define MALLCHECK(x) if (!x) return (0)
# define INDENT_PCT 0.2

typedef struct	s_point
{
	float			x;
	float			y;
	float			z;
	struct s_point	*right;
	struct s_point	*down;
}				t_point;

typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*n;
	int				x;
	int				y;
	int				**map;
	float			scale;
	int				shx;
	int				shy;
	t_point			*p_arr;
	float			ax;
	float			ay;
	float			az;
}				t_fdf;

void			free_doublechar(char **w);
void			free_line(char *l);
void			free_all(char **w, char *l);
int				count_words(char **splitted_words);
int				count_y(t_fdf *st);
int				fill_lineint(char **w, int *l);
int				fillall_validate(t_fdf *st);
//void			draw_lines(t_fdf *st);
void	draw(t_fdf *st);

#endif
