/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:22 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 16:59:07 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*rt;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_int_len_count(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	n *= sign;
	rt = (char*)malloc(len + 1);
	if (!rt)
		return (NULL);
	rt[len] = '\0';
	while (len-- > 1)
	{
		rt[len] = n % 10 + '0';
		n /= 10;
	}
	rt[len] = sign == -1 ? '-' : (n % 10 + '0');
	return (rt);
}
