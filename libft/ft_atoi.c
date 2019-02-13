/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:52:40 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/06 14:57:28 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str_in)
{
	unsigned long long	num;
	int					sign;
	char				*str;
	int					numofdigits;

	num = 0;
	sign = 1;
	str = (char*)str_in;
	numofdigits = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= 0x30 && *str <= 0x39)
	{
		num = num * 10 + *(str++) - '0';
		if (++numofdigits > 19 || ((num > 9223372036854775807 && sign == 1) ||
		(num > 9223372036854775808U && sign == -1)))
			return (sign == 1 ? -1 : 0);
	}
	return ((int)num * sign);
}
