/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:51 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/19 14:37:12 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	main(int ac, char **av)
{
	t_fdf	st;

	if (ac != 2 || !st_init(&st, av[1]))
	{
		ft_putendl_fd("Error!", 2);
		return (0);
	}
	prepare_points(&st);
	draw(&st);
	printf("%f\n", st.scale);
	//mlx_pixel_put(st.mlx_ptr, st.win_ptr, 1, 1, COLOR);
    //mlx_pixel_put(st.mlx_ptr, st.win_ptr, 251, 250, 0x999999);
	mlx_key_hook(st.win_ptr, deal_key, (void *)&st);
	mlx_loop(st.mlx_ptr);
}