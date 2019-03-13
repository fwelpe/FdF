/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:57:11 by cdenys-a          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:18 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_iter;
	unsigned char	*src_iter;
	size_t			i;
	unsigned char	val;

	dst_iter = (unsigned char*)dst;
	src_iter = (unsigned char*)src;
	i = 0;
	val = (unsigned char)c;
	while (i < n)
	{
		dst_iter[i] = src_iter[i];
		if (dst_iter[i] == val)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
