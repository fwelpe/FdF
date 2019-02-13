/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/13 20:46:06 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (0);
}

void	calc_scale(t_fdf *st)
{
	float	tmp;

	tmp = (float)H / (st->y * 1.3);
	st->scale = (float)W / (st->x * 1.3);
	st->scale = tmp < st->scale ? tmp : st->scale;
	// st->scale = st->scale > 1 ? 1 : st->scale;
}

int		st_init(t_fdf *st, char *n)
{
	st->mlx_ptr = mlx_init();
	st->win_ptr = mlx_new_window(st->mlx_ptr, W, H, "эмеликсь пиксель пют");
	st->n = n;
	if (!fillall_validate(st))
		return (0);
	calc_scale(st);
	st->shx = W / 2 - ((float)st->x / 2 * st->scale);
	st->shy = H / 2 - ((float)st->y / 2 * st->scale);
	st->ax = 0.1667;
	st->ay = 0;
	st->az = 0.08333;
	return (1);
}

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (!st_init(&st, av[1]))
	{
		printf("Error!\n");
		return (0);
	}
	printf("%f\n", st.scale);
	draw_lines(&st);
	//mlx_pixel_put(st.mlx_ptr, st.win_ptr, 1, 1, COLOR);
    //mlx_pixel_put(st.mlx_ptr, st.win_ptr, 251, 250, 0x999999);
	mlx_key_hook(st.win_ptr, deal_key, (void *)0);
	mlx_loop(st.mlx_ptr);

}

/* int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_fdf	st;

	st.n = av[1];
	if (!fillall_validate(&st))
	{
		printf("Oops!\n");
		return (0);
	}
	i = 0;
	j = 0;
	while (i < st.y)
	{
		while (j < st.x)
		{
			printf("% 4i", st.map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
} */

/* int main()
{
	int q = 3;
	int w = 8;	
	float i = w / (float)q;
	printf("%i\n", (int)i);
} */