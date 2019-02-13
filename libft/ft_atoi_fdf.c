/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:52:40 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/11 19:01:26 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_fdf(char *str, int *num_in)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		if (!(*str >= 0x30 && *str <= 0x39))
			return (0);
		num = num * 10 + *(str++) - '0';
	}
	*num_in = num * sign;
	return (1);
}
