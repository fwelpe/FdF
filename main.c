/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/09 20:33:15 by fwlpe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook_f(int button,int x,int y, t_fdf *st)
{
	// printf("hey!\n");
	st->mouse->lastx = st->mouse->x;
	st->mouse->lasty = st->mouse->y;
	st->mouse->x = x;
	st->mouse->y = y;
	st->cam->x += (st->mouse->lasty - y) / 50.0f;
	st->cam->y -= (st->mouse->lastx - x) / 50.0f;
	copy_points(st->map);
	draw(st);
	return (0);
}

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		ft_putendl_fd("Error!", 2);
		return (0);
	}
	copy_points(st.map);
	init_mouse(&st);
	draw(&st);
	mlx_key_hook(st.win_ptr, deal_key, &st);
	mlx_hook(st.win_ptr, 4, 0, mouse_press, (void *)&st);
	mlx_hook(st.win_ptr, 5, 0, mouse_release, (void *)&st);
	mlx_hook(st.win_ptr, 6, 0, mouse_move, (void *)&st);
	mlx_mouse_hook(st.win_ptr, mouse_hook_f, (void *)&st);
	mlx_loop(st.mlx_ptr);
}
