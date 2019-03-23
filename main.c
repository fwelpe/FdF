/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/03/23 17:30:34 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		ft_putendl_fd("Error!", 2);
		return (1);
	}
	copy_points(st.map);
	init_mouse(&st);
	draw(&st);
	mlx_key_hook(st.win_ptr, deal_key, &st);
	mlx_hook(st.win_ptr, 4, 0, mouse_press, (void *)&st);
	mlx_hook(st.win_ptr, 5, 0, mouse_release, (void *)&st);
	mlx_hook(st.win_ptr, 6, 0, mouse_move, (void *)&st);
	mlx_hook(st.win_ptr, 17, 0, red_button, (void *)0);
	mlx_loop(st.mlx_ptr);
}
