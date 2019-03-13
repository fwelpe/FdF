/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:28:56 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:42 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	if (src < dst)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			u_dst[i] = u_src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			u_dst[i] = u_src[i];
			i++;
		}
	}
	return (dst);
}
